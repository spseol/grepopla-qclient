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
    Q_PROPERTY(bool following READ following WRITE setFollowing NOTIFY followingChanged)

    private:
        int m_type;
        QPoint m_destination;
        QUrl m_imageSource;    
        qreal m_rotationSpeed;  //how much miliseconds does it take to rotate by 1°
        qreal delta_rotation;
        int m_voyageDuration;
        bool m_following;

    public:
        explicit Ship(QQuickItem *parent = 0);

        enum ShipType { SmallShip, ColonisingShip };

        virtual void paint(QPainter *painter);

        Q_INVOKABLE qreal rotationDuration() const; //calculate duration of specific angle
        Q_INVOKABLE void startEmitDestination(Ship* follower);  //follow
        Q_INVOKABLE void stopEmitDestination(Ship* follower);   //stop follow

        int type() const;
        QPoint destination() const;
        QUrl imageSource() const;
        qreal rotationSpeed() const;
        int voyageDuration() const;

        bool following() const;

    signals:
        void imageSourceChanged(QUrl arg);
        void typeChanged(int arg);
        void destinationChanged(QPoint);
        void rotationSpeedChanged(qreal arg);
        void voyageDurationChanged(QPoint arg);

        void ppositionChanged(QPoint arg);

        void followingChanged(bool arg);

    private slots:
        void setVoyageDuration(QPoint arg); //calculate duration of specific distance
        void changeProperties(int arg); //change properties according to ship type --need to finish
        void rotate();  //choose type of rotation and rotate
        void emitDestination(); //becauso of passing Point through signal/slot

    public slots:
        void setType(int arg);
        void setDestination(QPoint arg);
        void setImageSource(QUrl arg);
        void setRotationSpeed(qreal arg);
        void setFollowing(bool arg);
};



#endif // SHIP_H
