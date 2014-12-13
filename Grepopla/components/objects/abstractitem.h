#ifndef ABSTRACTITEM_H
#define ABSTRACTITEM_H

#include <QQuickPaintedItem>
#include <QPainter>

class AbstractItem : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(qreal speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(QStringList colors READ colors WRITE setColors NOTIFY colorsChanged)
    Q_PROPERTY(int ID READ ID WRITE setID NOTIFY IDChanged)

    protected:
        qreal m_speed;
        QStringList m_colors;
        int m_ID;

    public:
        explicit AbstractItem(QQuickItem *parent = 0);
        virtual void paint(QPainter *painter) = 0;

        qreal speed() const;
        QStringList colors() const;
        int ID() const;

    signals:
        void speedChanged(qreal arg);
        void colorsChanged(QStringList arg);
        void IDChanged(int arg);

    public slots:
        void setSpeed(qreal arg);
        void setColors(QStringList arg);
        void setID(int arg);
};



#endif // ABSTRACTITEM_H
