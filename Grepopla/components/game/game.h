#ifndef GAME_H
#define GAME_H

#include <QQuickItem>
#include "player/player.h"
#include "../objects/ship/ShipOptions.h"

class Game : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(int planetCount READ planetCount WRITE setPlanetCount NOTIFY planetCountChanged)
    Q_PROPERTY(int playerCount READ playerCount WRITE setPlayerCount NOTIFY playerCountChanged)
    Q_PROPERTY(int myID READ myID WRITE setMyID NOTIFY myIDChanged)

    private:
        int m_planetCount;
        int m_playerCount;        
        int m_myID;

    public:
        explicit Game(QQuickItem *parent = 0);

        static ShipOptions *SmallShip;

        int planetCount() const;
        int playerCount() const;        
        int myID() const;

    signals:
        void restart();
        void start();
        void gameOver(int arg);
        void planetCountChanged(int arg);
        void playerCountChanged(int arg);       
        void myIDChanged(int arg);

    public slots:
        void setPlanetCount(int arg);
        void setPlayerCount(int arg);
        void setMyID(int arg);
};

#endif // GAME_H
