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
    Q_PROPERTY(qreal ratio READ ratio WRITE setRatio NOTIFY ratioChanged)

    protected:
        qreal m_speed;
        QStringList m_colors;
        int m_ID;
        static int IDLogger;
        qreal m_ratio;

    public:
        explicit AbstractItem(QQuickItem *parent = 0);
        virtual void paint(QPainter *painter) = 0;

        qreal speed() const;
        QStringList colors() const;
        int ID() const;       
        qreal ratio() const;

    signals:
        void speedChanged(qreal arg);
        void colorsChanged(QStringList arg);
        void IDChanged(int arg);      
        void ratioChanged(qreal arg);

    public slots:
        void setSpeed(qreal arg);
        void setColors(QStringList arg);
        void setID(int arg);
        void setRatio(qreal arg);
};



#endif // ABSTRACTITEM_H
