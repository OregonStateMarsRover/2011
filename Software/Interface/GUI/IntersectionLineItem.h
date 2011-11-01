#ifndef INTERSECTIONLINEITEM_H
#define INTERSECTIONLINEITEM_H

#include <QGraphicsLineItem>

class IntersectionLineItem : public QGraphicsLineItem
{
public:
    IntersectionLineItem(QGraphicsItem * parent = 0);
    IntersectionLineItem(QLineF & line, QGraphicsItem * parent = 0);
    ~IntersectionLineItem();
};

#endif // INTERSECTIONLINEITEM_H
