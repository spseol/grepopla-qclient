#include "planet.h"

Planet::Planet(QQuickItem *parent) :
    AbstractItem(parent)
{
}

void Planet::paint(QPainter *painter)
{
    painter->setBrush(QBrush(QColor("blue")));
    painter->drawEllipse(boundingRect());
    painter->setBrush(QBrush(QColor("white")));
    painter->setPen(QPen(QColor("white")));
    painter->drawText(boundingRect(), "1");

}

int Planet::population() const
{
    return m_population;
}

void Planet::handleCapturing(Player *conquerer)
{
    m_owner = conquerer;
}

void Planet::setPopulation(int arg)
{
    if (m_population == arg)
        return;

    m_population = arg;
    emit populationChanged(arg);
}
