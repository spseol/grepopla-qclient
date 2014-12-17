#include "ship.h"
#include <QtMath>
#include <QtSvg/QSvgRenderer>

Ship::Ship(QQuickItem *parent) :
    AbstractItem(parent)
{
    m_focus = false;
    m_following = false;
    m_counter = 0;
    m_updateDestination = false;

    QObject::connect(this, SIGNAL(xChanged()), this, SLOT(emitDestination()));
    QObject::connect(this, SIGNAL(yChanged()), this, SLOT(emitDestination()));
    QObject::connect(this, SIGNAL(destinationChanged(QPoint)), this, SLOT(setVoyageDuration(QPoint)));
    QObject::connect(this, SIGNAL(destinationChanged(QPoint)), this, SLOT(rotate()));
    QObject::connect(this, SIGNAL(typeChanged(int)), this, SLOT(changeProperties(int)));
}

void Ship::paint(QPainter *painter)
{
    //relative do not work
    QSvgRenderer renderer(m_imageSource.toString());

    renderer.render(painter);
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

    //add target to follower
    QVariantList list = follower->targetsID();
    list.append(this->m_ID);
    follower->setTargetsID(list);
    follower->setUpdateDestination(true);
    follower->setDestination(QPoint(0,0));

    emit positionChanged(position().toPoint());
}

void Ship::stopEmitDestination(Ship *follower)
{
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

QUrl Ship::imageSource() const
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

int Ship::lifes() const
{
    return m_lifes;
}

int Ship::currentLife() const
{
    return m_currentLife;
}

/*---------------------*/
/*-------SETTERS-------*/
/*---------------------*/

void Ship::setType(int arg)
{
    if (m_type == arg)
        return;

    m_type = arg;
    emit typeChanged(arg);
}

void Ship::setDestination(QPoint arg)
{
    if ((m_destination == arg && !m_updateDestination) || (!m_focus && !m_following && !m_updateDestination ))
        return;

    m_destination = arg;

    if(m_following)
        m_counter += 1;

    if((m_counter >= 15 && m_following) || m_focus || m_updateDestination)
    {
        m_counter = 0;
        m_updateDestination = false;
        QObject *animation = this->findChild<QObject*>("moveAnimation");
        QMetaObject::invokeMethod(animation, "stop");

        emit destinationChanged(arg);
    }
}

void Ship::setImageSource(QUrl arg)
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
    m_updateDestination = arg;
}

void Ship::setCurrentLife(int arg)
{
    if (m_currentLife == arg)
        return;

    m_currentLife = arg;
    emit currentLifeChanged(arg);
}

void Ship::setVoyageDuration(QPoint arg)
{
    qreal distance = sqrt(pow(arg.x() - this->x(), 2) + pow(arg.y() - this->y(), 2));
    m_voyageDuration = distance * m_speed;
    emit voyageDurationChanged(arg);
}

void Ship::changeProperties(int arg)
{
    switch (arg) {  //dokončit
        case SmallShip:
            this->setSpeed(9);
            this->setRatio(0.2);
            break;
    }
}
