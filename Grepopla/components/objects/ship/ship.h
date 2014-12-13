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
    Q_PROPERTY(QPoint destination READ destination WRITE setDestination NOTIFY destinationChanged)
    Q_PROPERTY(QUrl imageSource READ imageSource WRITE setImageSource NOTIFY imageSourceChanged)

    private:
        int m_type;
        QPoint m_destination;
        QUrl m_imageSource;

    public:
        explicit Ship(QQuickItem *parent = 0);

        enum ShipType { SmallShip ,ColonisingShip };

        virtual void paint(QPainter *painter);
        Q_INVOKABLE qreal calculateRotation();

        int type() const;
        QPoint destination() const;
        QUrl imageSource() const;

    signals:
        void follow(int arg);
        void isFollowed(int arg);
        void isDisfollowed(int arg);

        void imageSourceChanged(QUrl arg);
        void typeChanged(int arg);
        void destinationChanged(QPoint arg);

    public slots:
        void setType(int arg);
        void setDestination(QPoint arg);
        void setImageSource(QUrl arg);
};



#endif // SHIP_H
