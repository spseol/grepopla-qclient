#ifndef ABSTRACTITEM_H
#define ABSTRACTITEM_H

#include <QQuickPaintedItem>
#include <QPainter>

class AbstractItem : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(QStringList colors READ colors WRITE setColors NOTIFY colorsChanged)
    Q_PROPERTY(int ID READ ID WRITE setID NOTIFY IDChanged)
    Q_PROPERTY(qreal ratio READ ratio WRITE setRatio NOTIFY ratioChanged)
    Q_PROPERTY(bool focus READ focus WRITE setFocus NOTIFY focusChanged)

    protected:
        QStringList m_colors;
        int m_ID;
        static int IDLogger;
        qreal m_ratio;
        bool m_focus;

    public:
        explicit AbstractItem(QQuickItem *parent = 0);
        virtual void paint(QPainter *painter) = 0;

        QStringList colors() const;
        int ID() const;       
        qreal ratio() const;
        bool focus() const;

    signals:
        void colorsChanged(QStringList arg);
        void IDChanged(int arg);      
        void ratioChanged(qreal arg);
        void focusChanged(bool arg);

    public slots:
        void setColors(QStringList arg);
        void setID(int arg);
        void setRatio(qreal arg);
        void setFocus(bool arg);
};





#endif // ABSTRACTITEM_H
