#include "player.h"

Player::Player(QQuickItem *parent) :
    QQuickItem(parent)
{
}

/*---------------------*/
/*-------GETTERS-------*/
/*---------------------*/

int Player::ID() const
{
    return m_ID;
}

QColor Player::color() const
{
    return m_color;
}

/*---------------------*/
/*-------SETTERS-------*/
/*---------------------*/

void Player::setID(int arg)
{
    if (m_ID == arg)
        return;

    m_ID = arg;
    emit IDChanged(arg);
}

void Player::setColor(QColor arg)
{
    if (m_color == arg)
        return;

    m_color = arg;
    emit colorChanged(arg);
}
