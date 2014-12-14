#include "abstractitem.h"

int AbstractItem::IDLogger = 0;

AbstractItem::AbstractItem(QQuickItem *parent) :
    QQuickPaintedItem(parent)
{
    m_ID = IDLogger++;
}

/*---------------------*/
/*-------GETTERS-------*/
/*---------------------*/

qreal AbstractItem::speed() const
{
    return m_speed;
}

QStringList AbstractItem::colors() const
{
    return m_colors;
}


int AbstractItem::ID() const
{
    return m_ID;
}

qreal AbstractItem::ratio() const
{
    return m_ratio;
}

/*---------------------*/
/*-------SETTERS-------*/
/*---------------------*/

void AbstractItem::setSpeed(qreal arg)
{
    if (m_speed == arg)
        return;

    m_speed = arg;
    emit speedChanged(arg);
}

void AbstractItem::setColors(QStringList arg)
{
    if (m_colors == arg)
        return;

    m_colors = arg;
    emit colorsChanged(arg);
}

void AbstractItem::setID(int arg)
{
    if (m_ID == arg)
        return;

    m_ID = arg;
    emit IDChanged(arg);
}

void AbstractItem::setRatio(qreal arg)
{
    if (m_ratio == arg)
        return;

    m_ratio = arg;
    emit ratioChanged(arg);
}
