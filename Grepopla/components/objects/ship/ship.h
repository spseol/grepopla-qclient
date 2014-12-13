#ifndef SHIP_H
#define SHIP_H

#include <QQuickPaintedItem>
#include <QPainter>
#include "../abstractitem.h"

class Ship : public AbstractItem
{
    Q_OBJECT

    Q_ENUMS(ShipType)
    Q_PROPERTY(int type READ type WRITE setType NOTIFY typeChanged)

    int m_type;

    public:
        explicit Ship(QQuickItem *parent = 0);

        enum ShipType { SmallShip ,ColonisingShip };
        virtual void paint(QPainter *painter);

        int type() const;

    signals:
        void typeChanged(int arg);

        void follow(int arg);
        void isFollowed(int arg);
        void isDisfollowed(int arg);

    public slots:
        void setType(int arg);
};



#endif // SHIP_H
