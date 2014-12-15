#include "ship.h"
#include <QtMath>
#include <QtSvg/QSvgRenderer>

Ship::Ship(QQuickItem *parent) :
    AbstractItem(parent)
{
    m_focus = false;

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
    if (m_destination == arg || !m_focus)
        return;

    m_destination = arg;

    QObject *animation = this->findChild<QObject*>("moveAnimation");
    QMetaObject::invokeMethod(animation, "stop");

    emit destinationChanged(arg);
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












