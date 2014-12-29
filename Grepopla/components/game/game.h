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
    Q_PROPERTY(QString myNick READ myNick WRITE setMyNick NOTIFY myNickChanged)

    private:
        int m_planetCount;
        int m_playerCount;        
        int m_myID;

        QString m_myNick;

    public:
        explicit Game(QQuickItem *parent = 0);

        static ShipOptions *SmallShip;

        int planetCount() const;
        int playerCount() const;        
        int myID() const;        
        QString myNick() const;

    signals:
        void restart();
        void start();
        void gameOver(int arg);
        void planetCountChanged(int arg);
        void playerCountChanged(int arg);       
        void myIDChanged(int arg);        
        void myNickChanged(QString arg);

    public slots:
        void setPlanetCount(int arg);
        void setPlayerCount(int arg);
        void setMyID(int arg);
        void setMyNick(QString arg);
};

#endif // GAME_H
