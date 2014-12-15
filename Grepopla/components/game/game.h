#ifndef GAME_H
#define GAME_H

#include <QQuickItem>
#include "player/player.h"

class Game : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(int planetCount READ planetCount WRITE setPlanetCount NOTIFY planetCountChanged)
    Q_PROPERTY(int playerCount READ playerCount WRITE setPlayerCount NOTIFY playerCountChanged)

    private:
        int m_planetCount;
        int m_playerCount;

    public:
        explicit Game(QQuickItem *parent = 0);

        int planetCount() const;
        int playerCount() const;

    signals:
        void restart();
        void start();
        void gameOver(Player *arg);
        void planetCountChanged(int arg);
        void playerCountChanged(int arg);

    public slots:
        void setPlanetCount(int arg);
        void setPlayerCount(int arg);
};

#endif // GAME_H
