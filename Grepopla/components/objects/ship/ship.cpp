#include "ship.h"
#include <QtMath>
#include <QtSvg/QSvgRenderer>

Ship::Ship(QQuickItem *parent) :
    AbstractItem(parent)
{
}

void Ship::paint(QPainter *painter)
{
    //relative do not work
    QSvgRenderer renderer(QString("C:/Users/Sony/Documents/grepopla-qclient/Grepopla/resources/images/black_arrow.svg"));

    renderer.render(painter);
}

qreal Ship::calculateRotation()
{
    qreal dx = m_destination.x();
    qreal dy = m_destination.y();
    qreal angle = qAtan2(dx - this->x(), this->y() - dy) / M_PI * 180.0;    //in degrees

    if(360 - abs(angle) > abs(angle))
        return angle;
    else
        return 360 - abs(angle);
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
    if (m_destination == arg)
        return;

    m_destination = arg;
    emit destinationChanged(arg);
}

void Ship::setImageSource(QUrl arg)
{
    if (m_imageSource == arg)
        return;

    m_imageSource = arg;
    emit imageSourceChanged(arg);
}
