#include "show_score.h"
#include "global.h"
#include <QGraphicsScene>

Show_score::Show_score(qreal w,qreal h,int* score,QGraphicsScene *scene,QGraphicsItem *parent)
    :QGraphicsObject(parent)
{
    s_score = score;
    QPixmap temp;
    temp = QPixmap(Num_1_Pic);
    s_num_pic = temp;
    scene->addItem(this);
    setPos(w,h);
}


void Show_score::advance(int step)
{
    ;
}

QRectF Show_score::boundingRect()const
{
 return s_num_pic.rect();
}

void Show_score::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   painter->drawPixmap(0,0,Num_H,Num_W,s_num_pic);
   painter->drawPixmap(Interval,0,Num_H,Num_W,s_num_pic);
   painter->drawPixmap(Interval*2,0,Num_H,Num_W,s_num_pic);
}



QPainterPath Show_score::shape()const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}
