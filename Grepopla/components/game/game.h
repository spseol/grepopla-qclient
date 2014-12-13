#ifndef GAME_H
#define GAME_H

#include <QQuickItem>
//#include "player/player.h"

class Game : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(int planetCount READ planetCount WRITE setPlanetCount NOTIFY planetCountChanged)

    int m_planetCount;

public:
        explicit Game(QQuickItem *parent = 0);

    int planetCount() const;

signals:
        //void gameOver(Player arg);

        void planetCountChanged(int arg);

public slots:

    void setPlanetCount(int arg);
};

#endif // GAME_H
