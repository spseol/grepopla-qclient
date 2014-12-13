#ifndef PLAYER_H
#define PLAYER_H

#include <QQuickItem>
#include "../../objects/ship/ship.h"

class Player : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(int ID READ ID WRITE setID NOTIFY IDChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

    private:
        int m_ID;
        QColor m_color;

    public:
        explicit Player(QQuickItem *parent = 0);

        int ID() const;
        QColor color() const;

    signals:
        void IDChanged(int arg);
        void colorChanged(QColor arg);

    public slots:
        void setID(int arg);
        void setColor(QColor arg);
};

#endif // PLAYER_H
