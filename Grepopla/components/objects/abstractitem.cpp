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

void AbstractItem::setFocus(bool arg)
{
    if (m_focus == arg)
        return;

    m_focus = arg;
    emit focusChanged(arg);
}

void AbstractItem::setOwner(Player *arg)
{
    if (m_owner == arg)
        return;

    m_owner = arg;
    emit ownerChanged(arg);
}


bool AbstractItem::focus() const
{
    return m_focus;
}

Player *AbstractItem::owner() const
{
    return m_owner;
}
