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

int Player::population() const
{
    return m_population;
}

int Player::maxPopulation() const
{
    return m_maxPopulation;
}

QString Player::nick() const
{
    return m_nick;
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

void Player::setPopulation(int arg)
{
    if (m_population == arg)
        return;

    m_population = arg;
    emit populationChanged(arg);
}

void Player::setMaxPopulation(int arg)
{
    if (m_maxPopulation == arg)
        return;

    m_maxPopulation = arg;
    emit maxPopulationChanged(arg);
}

void Player::setNick(QString arg)
{
    if (m_nick == arg)
        return;

    m_nick = arg;
    emit nickChanged(arg);
}
