#include "game.h"

Game::Game(QQuickItem *parent) :
    QQuickItem(parent)
{
}

int Game::planetCount() const
{
    return m_planetCount;
}

int Game::playerCount() const
{
    return m_playerCount;
}

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
