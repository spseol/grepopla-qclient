#ifndef PLAYER_H
#define PLAYER_H

#include <QQuickItem>

class Player : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(int ID READ ID WRITE setID NOTIFY IDChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int population READ population WRITE setPopulation NOTIFY populationChanged)
    Q_PROPERTY(int maxPopulation READ maxPopulation WRITE setMaxPopulation NOTIFY maxPopulationChanged)

    private:
        int m_ID;
        QColor m_color;
        int m_population;
        int m_maxPopulation;

    public:
        explicit Player(QQuickItem *parent = 0);

        int ID() const;
        QColor color() const;
        int population() const;
        int maxPopulation() const;

    signals:
        void IDChanged(int arg);
        void colorChanged(QColor arg);
        void populationChanged(int arg);
        void maxPopulationChanged(int arg);

    public slots:
        void setID(int arg);
        void setColor(QColor arg);
        void setPopulation(int arg);
        void setMaxPopulation(int arg);
};

#endif // PLAYER_H
