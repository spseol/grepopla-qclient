#include "ship.h"

Ship::Ship(QQuickItem *parent) :
    AbstractItem(parent)
{
}

void Ship::paint(QPainter *painter)
{

}

void Ship::follow(int arg)
{

}

int Ship::type() const
{
    return m_type;
}

void Ship::setType(int arg)
{
    if (m_type == arg)
        return;

    m_type = arg;
    emit typeChanged(arg);
}
