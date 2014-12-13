#ifndef PLANET_H
#define PLANET_H

#include <QQuickPaintedItem>
#include "../abstractitem.h"

class Planet : public AbstractItem
{
    Q_OBJECT

    public:
        explicit Planet(QQuickItem *parent = 0);

        virtual void paint(QPainter *painter);
};

#endif // PLANET_H
