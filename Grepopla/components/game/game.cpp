#include "game.h"
ShipOptions *Game::SmallShip = new ShipOptions(4, 50, 1);

Game::Game(QQuickItem *parent) :
    QQuickItem(parent)
{
}

/*---------------------*/
/*-------GETTERS-------*/
/*---------------------*/

int Game::planetCount() const
{
    return m_planetCount;
}

int Game::playerCount() const
{
    return m_playerCount;
}

int Game::myID() const
{
    return m_myID;
}

QString Game::myNick() const
{
    return m_myNick;
}

/*---------------------*/
/*-------SETTERS-------*/
/*---------------------*/

void Game::setPlanetCount(int arg)
{
    if (m_planetCount == arg)
        return;

    m_planetCount = arg;
    emit planetCountChanged(arg);
}

void Game::setPlayerCount(int arg)
{
    if (m_playerCount == arg)
        return;

    m_playerCount = arg;
    emit playerCountChanged(arg);
}

void Game::setMyID(int arg)
{
    if (m_myID == arg)
        return;

    m_myID = arg;
    emit myIDChanged(arg);
}

void Game::setMyNick(QString arg)
{
    if (m_myNick == arg)
        return;

    m_myNick = arg;
    emit myNickChanged(arg);
}
