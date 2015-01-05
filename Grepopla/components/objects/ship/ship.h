#ifndef SHIP_H
#define SHIP_H

#include <QQuickPaintedItem>
#include <QPainter>
#include "../abstractitem.h"
#include "../../game/game.h"
#include "ShipOptions.h"

class Ship : public AbstractItem
{
    Q_OBJECT

    Q_ENUMS(ShipType)
    Q_PROPERTY(int type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QPoint destination READ destination WRITE setDestination NOTIFY destinationChanged)
    Q_PROPERTY(QString imageSource READ imageSource WRITE setImageSource NOTIFY imageSourceChanged)
    Q_PROPERTY(qreal rotationSpeed READ rotationSpeed WRITE setRotationSpeed NOTIFY rotationSpeedChanged)
    Q_PROPERTY(int voyageDuration READ voyageDuration NOTIFY voyageDurationChanged)
    Q_PROPERTY(bool following READ following WRITE setFollowing NOTIFY followingChanged)
    Q_PROPERTY(QVariantList targetsID READ targetsID WRITE setTargetsID NOTIFY targetsIDChanged)
    Q_PROPERTY(int currentHP READ currentHP WRITE setCurrentHP NOTIFY currentHPChanged)
    Q_PROPERTY(bool updateDestination READ updateDestination WRITE setUpdateDestination NOTIFY updateDestinationChanged)

    private:
        //ship properties
        int m_type;
        int m_currentHP;
        ShipOptions *m_properties;

        //calculation properties
        QPoint m_destination;
        QString m_imageSource;
        qreal m_rotationSpeed;  //how much miliseconds does it take to rotate by 1°
        qreal delta_rotation;
        int m_voyageDuration;

        //following properties
        bool m_following;
        bool m_updateDestination;   //I do not move, but emit my position
        QVariantList m_targetsID;
        QList<Ship*> m_followers;   //not Twitter followers

    public:
        explicit Ship(QQuickItem *parent = 0);

        enum ShipType { SmallShip, ColonisingShip };

        virtual void paint(QPainter *painter);

        Q_INVOKABLE qreal rotationDuration() const; //calculate duration of specific angle
        Q_INVOKABLE void startEmitDestination(Ship* follower);  //follow
        Q_INVOKABLE void stopEmitDestination(Ship* follower);   //stop follow

        int type() const;
        QPoint destination() const;
        QString imageSource() const;
        qreal rotationSpeed() const;
        int voyageDuration() const;
        bool following() const;
        QVariantList targetsID() const;
        int currentHP() const;      
        bool updateDestination() const;

    signals:
        void imageSourceChanged(QString arg);
        void typeChanged(int arg);
        void destinationChanged(QPoint arg);
        void rotationSpeedChanged(qreal arg);
        void voyageDurationChanged(QPoint arg);
        void positionChanged(QPoint arg);
        void followingChanged(bool arg);
        void targetsIDChanged(QVariantList arg);
        void currentHPChanged(int arg);     
        void updateDestinationChanged(bool arg);

    private slots:
        void setVoyageDuration(QPoint arg); //calculate duration of specific distance
        void rotate();  //choose type of rotation and rotate
        void emitDestination(); //because of passing Point through signal/slot

    public slots:
        void setInactive(); //need to tell everyone to stop follow me

        void setType(int arg);
        void setDestination(QPoint arg);
        void setImageSource(QString arg);
        void setRotationSpeed(qreal arg);
        void setFollowing(bool arg);
        void setTargetsID(QVariantList arg);
        void setUpdateDestination(bool arg);
        void setCurrentHP(int arg);
};





#endif // SHIP_H
