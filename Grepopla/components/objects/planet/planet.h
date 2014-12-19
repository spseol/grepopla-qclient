#ifndef PLANET_H
#define PLANET_H

#include <QQuickPaintedItem>
#include <QTimer>
#include "../abstractitem.h"
#include "../../../components/game/player/player.h"
#include "../../game/game.h"

class Planet : public AbstractItem
{
    Q_OBJECT

    Q_PROPERTY(int population READ population WRITE setPopulation NOTIFY populationChanged)

    private:
        QTimer m_buildTimer;
        QTimer m_capturingTimer;
        int m_population;

    public:
        explicit Planet(QQuickItem *parent = 0);

        virtual void paint(QPainter *painter);

        int population() const;

    public slots:
        void handleCapturing(Player* conquerer);

        void setPopulation(int arg);

    signals:
        void shipFinished(int ID);
        void buildShip(int type);

        void populationChanged(int arg);
};

#endif // PLANET_H
