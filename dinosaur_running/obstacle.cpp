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
     k_flag=0;
     if(*flag_run==3)
     {
         *flag_run==1;
         k_flag=1;
         //qDebug()<<"bird!!";
     }
     the_flag=flag_run;
     o_play=play;
     O_Pix= pixs.scaled(Obs_W,Obs_H,Qt::KeepAspectRatioByExpanding);
     k_step=0;
     scene->addItem(this);
     setPos(w,h);
     anim_move =new QPropertyAnimation(this,"pos");
     anim_move->setDuration(During_time);
     anim_move->setStartValue(QPoint(w,h));
     anim_move->setEndValue(QPoint(w-1500,h));
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
     if(k_flag==1&&k_step%10==0)
     {
         O_Pix=QPixmap(":/new/obstacle_3.png").scaled(Obs_W,Obs_H,Qt::KeepAspectRatioByExpanding);
         update();
     }
     if(k_flag==1&&k_step%10==5)
     {
         O_Pix=QPixmap(":/new/obstacle_4.png").scaled(Obs_W,Obs_H,Qt::KeepAspectRatioByExpanding);
         update();
     }

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

