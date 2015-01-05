#include "ship.h"
#include <QtMath>
#include <QtSvg/QSvgRenderer>

void Ship::setInactive()
{
    foreach (Ship* follower, m_followers)
    {
        //remove me from list of targets
        QVariantList targets = follower->targetsID();
        targets.removeOne(m_ID);
        follower->setTargetsID(targets);
    }

    deleteLater();
}

Ship::Ship(QQuickItem *parent) :
    AbstractItem(parent)
{
    m_focus = false;
    m_following = false;
    m_updateDestination = false;
    m_properties = Game::SmallShip;

    //my position changed. Follow me!
    QObject::connect(this, SIGNAL(xChanged()), this, SLOT(emitDestination()));
    QObject::connect(this, SIGNAL(yChanged()), this, SLOT(emitDestination()));

    //I have to calculate duration of my voyage
    QObject::connect(this, SIGNAL(destinationChanged(QPoint)), this, SLOT(setVoyageDuration(QPoint)));
    //as well as duration of my rotation
    QObject::connect(this, SIGNAL(destinationChanged(QPoint)), this, SLOT(rotate()));
}

void Ship::paint(QPainter *painter)
{
    QSvgRenderer *renderer = new QSvgRenderer(m_imageSource);
    renderer->render(painter);
}

void Ship::rotate()
{
    qreal dx = m_destination.x();
    qreal dy = m_destination.y();
    qreal angle = qAtan2(dx - this->x(), this->y() - dy) / M_PI * 180.0;    //in degrees
    delta_rotation = abs(this->property("rotation").toDouble() - angle);

    if(360 - abs(angle) > abs(angle))
        this->setProperty("rotation", angle);
    else
        this->setProperty("rotation", 360 - abs(angle));
}

void Ship::emitDestination()
{
    emit positionChanged(position().toPoint());
}

void Ship::startEmitDestination(Ship* follower)
{
    follower->setFollowing(true);
    QObject::connect(this, SIGNAL(positionChanged(QPoint)), follower, SLOT(setDestination(QPoint)));

    //add follower somewhere, so I could know, who is following me
    m_followers.append(follower);

    //add target to follower
    QVariantList list = follower->targetsID();  //add me to the follower as target
    list.append(this->m_ID);

    follower->setTargetsID(list);   //tell to the follower to follow me although I do not move
    follower->setUpdateDestination(true);   //and I have to tell him to skip counter and follow me immediately

    emit positionChanged(position().toPoint());
}

void Ship::stopEmitDestination(Ship *follower)
{
    //you stoped following me? I remove you from my list
    m_followers.removeOne(follower);

    follower->setFollowing(false);
    QObject::disconnect(this, SIGNAL(positionChanged(QPoint)), follower, SLOT(setDestination(QPoint)));
}

qreal Ship::rotationDuration() const
{
    return  delta_rotation * m_rotationSpeed;
}

/*---------------------*/
/*-------GETTERS-------*/
/*---------------------*/

int Ship::type() const
{
    return m_type;
}

QPoint Ship::destination() const
{
    return m_destination;
}

QString Ship::imageSource() const
{
    return m_imageSource;
}

qreal Ship::rotationSpeed() const
{
    return m_rotationSpeed;
}

int Ship::voyageDuration() const
{
    return m_voyageDuration;
}

bool Ship::following() const
{
    return m_following;
}

QVariantList Ship::targetsID() const
{
    return m_targetsID;
}

int Ship::currentHP() const
{
    return m_currentHP;
}

bool Ship::updateDestination() const
{
    return m_updateDestination;
}

/*---------------------*/
/*-------SETTERS-------*/
/*---------------------*/

void Ship::setType(int arg)
{
    if (m_type == arg)
        return;

    m_type = arg;

    if(arg == SmallShip)
        m_properties = Game::SmallShip;

    emit typeChanged(arg);
}

void Ship::setDestination(QPoint arg)
{
    if ((m_destination == arg && !m_updateDestination) || (!m_focus && !m_following && !m_updateDestination ))
        return;

    static int counter = 0; //because of speed of animation, just can't handle update every milisecond
    m_destination = arg;

    if(m_following)
        counter += 1;

    if((counter >= 15 && m_following) || (m_focus && !m_following) || m_updateDestination)
    {
        qDebug() << "----------------";
        counter = 0;
        m_updateDestination = false;
        QObject *animation = this->findChild<QObject*>("moveAnimation");
        QMetaObject::invokeMethod(animation, "stop");

        emit destinationChanged(arg);
    }
}

void Ship::setImageSource(QString arg)
{
    if (m_imageSource == arg)
        return;

    m_imageSource = arg;
    emit imageSourceChanged(arg);
}

void Ship::setRotationSpeed(qreal arg)
{
    if (m_rotationSpeed == arg)
        return;

    m_rotationSpeed = arg;
    emit rotationSpeedChanged(arg);
}

void Ship::setFollowing(bool arg)
{
    if (m_following == arg)
        return;

    m_following = arg;
    emit followingChanged(arg);
}

void Ship::setTargetsID(QVariantList arg)
{
    if (m_targetsID == arg)
        return;

    m_targetsID = arg;
    emit targetsIDChanged(arg);
}

void Ship::setUpdateDestination(bool arg)
{
    if(m_updateDestination == arg)
        return;

    m_updateDestination = arg;
    emit updateDestinationChanged(arg);
}

void Ship::setCurrentHP(int arg)
{
    if (m_currentHP == arg)
        return;

    m_currentHP = arg;
    emit currentHPChanged(arg);
}

void Ship::setVoyageDuration(QPoint arg)
{
    qreal distance = sqrt(pow(arg.x() - this->x(), 2) + pow(arg.y() - this->y(), 2));
    m_voyageDuration = distance * m_properties->speed;
    emit voyageDurationChanged(arg);
}
