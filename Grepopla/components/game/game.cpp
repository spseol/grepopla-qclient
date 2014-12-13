#include "game.h"

Game::Game(QQuickItem *parent) :
    QQuickItem(parent)
{
}

int Game::planetCount() const
{
    return m_planetCount;
}

void Game::setPlanetCount(int arg)
{
    if (m_planetCount == arg)
        return;

    m_planetCount = arg;
    emit planetCountChanged(arg);
}
