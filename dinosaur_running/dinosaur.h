#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <QPainter>
#include <QPainterPath>
#include <QObject>
#include <QtWidgets>
#include <QPixmap>
#include "global.h"
#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QAnimationGroup>
#include <QPropertyAnimation>
#include <QPoint>
#include <QState>
#include <QStateMachine>

class dinosaur:public QGraphicsObject
{
    Q_OBJECT
public:
    dinosaur(qreal w,qreal h,const QPixmap &pixs,QGraphicsScene *scene,QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void fall();
    void doCollide();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~dinosaur();
    void advance(int step);
    void posLost();
    //virtual int name() const = 0;
    int state_flag;
    QSequentialAnimationGroup *Group;
    QPixmap m_pixs,dino_left,dino_right,dino_left_down,dino_right_down,dino_jump;
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
protected:
    QPropertyAnimation *anim_up,*anim_down;
    QStateMachine *Machine;
    QState *s1,*s2,*s3;
    qreal m_pixpos;
    int m_step;
    qreal w;
    qreal h;

signals:
    void    dead();
    void    upkey();
    void    downkey();
    void    releasekey();
protected slots:
    void slt_s1_in();
    void slt_s2_in();
    void slt_s3_in();

};

#endif // DINOSAUR_H
