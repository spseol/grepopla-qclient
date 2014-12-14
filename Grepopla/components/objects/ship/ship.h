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
    Q_PROPERTY(qreal rotationSpeed READ rotationSpeed WRITE setRotationSpeed NOTIFY rotationSpeedChanged)
    Q_PROPERTY(int voyageDuration READ voyageDuration NOTIFY voyageDurationChanged)

    private:
        int m_type;
        QPoint m_destination;
        QUrl m_imageSource;    
        qreal m_rotationSpeed;  //how much miliseconds does it take to rotate by 1°
        qreal delta_rotation;
        int m_voyageDuration;

    public:
        explicit Ship(QQuickItem *parent = 0);

        enum ShipType { SmallShip, ColonisingShip };

        virtual void paint(QPainter *painter);

        Q_INVOKABLE qreal rotationDuration() const;

        int type() const;
        QPoint destination() const;
        QUrl imageSource() const;
        qreal rotationSpeed() const;
        int voyageDuration() const;

    signals:
        void follow(int arg);
        void isFollowed(int arg);
        void isDisfollowed(int arg);

        void imageSourceChanged(QUrl arg);
        void typeChanged(int arg);
        void destinationChanged(QPoint);
        void rotationSpeedChanged(qreal arg);
        void voyageDurationChanged(QPoint arg);

    private slots:
        void setVoyageDuration(QPoint arg);
        void changeProperties(int arg);
        void rotate();

    public slots:
        void setType(int arg);
        void setDestination(QPoint arg);
        void setImageSource(QUrl arg);
        void setRotationSpeed(qreal arg);
};



#endif // SHIP_H
