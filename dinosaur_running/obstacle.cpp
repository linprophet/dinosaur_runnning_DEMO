#include "obstacle.h"
#include <QGraphicsItem>
#include <QGraphicsObject>
#include<QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include "global.h"
#include <QPropertyAnimation>
#include <QDebug>

Obstacle::Obstacle(qreal w,qreal h,const QPixmap &pixs,QGraphicsScene *scene,QGraphicsItem *parent)
:QGraphicsObject(parent)
{
     O_Pix= pixs.scaled(Obs_W,Obs_H,Qt::KeepAspectRatioByExpanding);
     scene->addItem(this);
     setPos(w,h);
     anim_move =new QPropertyAnimation(this,"pos");
     anim_move->setDuration(Dur_Time_obs);
     anim_move->setStartValue(QPoint(O_Pos_X,O_Pos_Y));
     anim_move->setEndValue(QPoint(O_Pos_X-1000,O_Pos_Y));
     anim_move->setEasingCurve(QEasingCurve::Linear);
     anim_move->start();
     //可能有BUG
    //connect(anim_move, SIGNAL(finished()), this,SLOT(slt_eimt_del()));


}
void Obstacle::advance(int step)
{

}

QRectF Obstacle::boundingRect()const
{
 return O_Pix.rect();
}

void Obstacle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   painter->drawPixmap(0,0,Obs_W,Obs_H,O_Pix);
}

QPainterPath Obstacle::shape()const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}
/*
void Obstacle::slt_eimt_del()
{
    emit delt();
}
*/
