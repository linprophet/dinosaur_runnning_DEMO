#include "obstacle.h"
#include <QGraphicsItem>
#include <QGraphicsObject>
#include<QGraphicsScene>
#include <QPainter>
#include <QPixmap>
#include "global.h"
#include <QPropertyAnimation>
#include <QDebug>

Obstacle::Obstacle(qreal w, qreal h, const QPixmap &pixs, dinosaur *play, QGraphicsScene *scene, int During_time, int *flag_run, QGraphicsItem *parent)
:QGraphicsObject(parent)
{
     the_flag=flag_run;
     o_play=play;
     O_Pix= pixs.scaled(Obs_W,Obs_H,Qt::KeepAspectRatioByExpanding);
     k_step=0;
     scene->addItem(this);
     setPos(w,h);
     anim_move =new QPropertyAnimation(this,"pos");
     anim_move->setDuration(During_time);
     anim_move->setStartValue(QPoint(O_Pos_X,O_Pos_Y));
     anim_move->setEndValue(QPoint(O_Pos_X-1500,O_Pos_Y));
     anim_move->setEasingCurve(QEasingCurve::Linear);
     anim_move->start();
     //可能有BUG
    //connect(anim_move, SIGNAL(finished()), this,SLOT(slt_eimt_del()));
    //connect(o_play,SIGNAL(dead()),this,SLOT(slt_eimt_del()));

}
void Obstacle::advance(int step)
{
    if (k_step==(Dur_Time_obs/30))
          {
               delete this;
            }
          k_step++;
     if(*the_flag==0)
     {
         slt_eimt_del();
     }

}



QRectF Obstacle::boundingRect()const
{
 return O_Pix.rect();
}

void Obstacle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   painter->drawPixmap(0,0,O_Pix.width(),O_Pix.height(),O_Pix);
}

QPainterPath Obstacle::shape()const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Obstacle::slt_eimt_del()
{
   // qDebug()<<"OK!!!";
    anim_move->stop();
}

