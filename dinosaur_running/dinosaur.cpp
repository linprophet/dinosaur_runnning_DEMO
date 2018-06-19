#include "dinosaur.h"
#include <QDebug>
#include <global.h>
#include <QPointF>
#include <QList>

dinosaur::dinosaur(qreal w,qreal h,const QPixmap &pixs,QGraphicsScene *scene,QGraphicsItem *parent)
    :QGraphicsObject(parent),m_pixpos(0),m_step(0),state_flag(1)
{
     m_pixs=pixs.scaled(Play_W,Play_H,Qt::KeepAspectRatioByExpanding);
     dino_jump=m_pixs;
     scene->addItem(this);
     setPos(w,h);//这个坐标是哪个系？？
     setFlag(QGraphicsItem::ItemIsFocusable);
     QPixmap temp;
     temp=QPixmap(Dino_Pic_Left);
     dino_left=temp.scaled(Play_W,Play_H,Qt::KeepAspectRatioByExpanding);
     temp=QPixmap(Dino_Pic_Right);
     dino_right=temp.scaled(Play_W,Play_H,Qt::KeepAspectRatioByExpanding);
     temp=QPixmap(Dino_Pic_Down_Left);
     dino_left_down=temp.scaled(Play_Down_W,Play_Down_H,Qt::KeepAspectRatioByExpanding);
     temp=QPixmap(Dino_Pic_Down_Right);
     dino_right_down=temp.scaled(Play_Down_W,Play_Down_H,Qt::KeepAspectRatioByExpanding);


     Group = new QSequentialAnimationGroup;
     anim_down =new QPropertyAnimation(this,"pos");
     anim_up = new QPropertyAnimation(this,"pos");

     anim_down->setDuration(Dur_Time);
     anim_down->setStartValue(QPoint(D_Pos_X,D_Pos_Y-Up_Distance));
     anim_down->setEndValue(QPoint(D_Pos_X,D_Pos_Y));
     anim_down->setEasingCurve(QEasingCurve::InSine);

     anim_up->setDuration(Dur_Time);
     anim_up->setStartValue(QPoint(D_Pos_X,D_Pos_Y));
     anim_up->setEndValue(QPoint(D_Pos_X,D_Pos_Y-Up_Distance));
     anim_up->setEasingCurve(QEasingCurve::OutSine);

     Group->addAnimation(anim_up);
     Group->addAnimation(anim_down);

     Machine = new QStateMachine;

     s1 = new QState();//原地跑
     s2 = new QState();//向上跳
     s3 = new QState();//下蹲

     Machine->addState(s1);
     Machine->addState(s2);
     Machine->addState(s3);
     Machine->setInitialState(s1);

     s1->addTransition(this,SIGNAL(upkey()),s2);
     s1->addTransition(this,SIGNAL(downkey()),s3);
     s2->addTransition(Group,SIGNAL(finished()),s1);
     s3->addTransition(this,SIGNAL(releasekey()),s1);
     connect(s1,SIGNAL(entered()),this,SLOT(slt_s1_in()));
     connect(s2,SIGNAL(entered()),this,SLOT(slt_s2_in()));
     connect(s3,SIGNAL(entered()),this,SLOT(slt_s3_in()));
     Machine->start();
}

dinosaur::~dinosaur()
{
    ;
}

QRectF dinosaur::boundingRect() const
{
    return m_pixs.rect();
}

QPainterPath dinosaur::shape()const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void dinosaur::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pixs);//这个绘制又是在哪个系？？
}


void dinosaur::fall()
{
    emit dead();
    qDebug()<<"Daed Event!";
}

void dinosaur::doCollide()
{
    QList<QGraphicsItem *> collisions = collidingItems(Qt::IntersectsItemShape);
    if(collisions.size()!=0)
    {
        fall();
    }
}

void dinosaur::advance(int step)
{
    m_step++;
    doCollide();
    if(state_flag==1&&m_step%Dino_Speed==0)
    {
        m_pixs=dino_left;
        update();
    }
    if(state_flag==1&&m_step%Dino_Speed==Dino_Speed/2)
    {
        m_pixs=dino_right;
        update();
    }
    if(state_flag==3&&m_step%Dino_Speed==0)
    {
        m_pixs=dino_left_down;
        update();
    }
    if(state_flag==3&&m_step%Dino_Speed==Dino_Speed/2)
    {
        m_pixs=dino_right_down;
        update();
    }
    if(m_step%50==0)
    {
        m_step=0;
    }
    //qDebug()<<m_step;
}

void dinosaur::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Up:
            event->accept();
            emit upkey();
            Group->start();
           // qDebug()<<"UP";
            break;
        case Qt::Key_Down:
            event->accept();
            emit downkey();
          //  qDebug()<<"Down";
            break;
        }
}

void dinosaur::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Down:
            event->accept();
            //qDebug()<<"Down";
            emit releasekey();
            break;
        }
}

void dinosaur::posLost()
{
    QPointF pos = scenePos();
    pos.ry() -= m_speed;
    setPos(pos);
}
void dinosaur::slt_s1_in()
{
    state_flag = 1;
    //qDebug()<<"slt_1!!";
}
void dinosaur::slt_s2_in()
{
    state_flag = 2;
    m_pixs=dino_jump;
    Group->start();
    //qDebug()<<"slt_2!!";
}
void dinosaur::slt_s3_in()
{
    state_flag = 3;
    //qDebug()<<"slt_3!!";
}