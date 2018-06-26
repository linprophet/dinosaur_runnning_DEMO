#ifndef OBSTACLE
#define OBSTACLE
#include <QApplication>
#include <QGraphicsObject>
#include <QPixmap>
#include <QPropertyAnimation>
#include "global.h"
#include <QtWidgets>
#include <QPainter>
#include <QPainterPath>
#include <QObject>
#include <QGraphicsItem>
#include <QPropertyAnimation>
#include "dinosaur.h"
//#include "space.h"
#include <QPoint>

typedef enum {UP, DOWN, LEFT, RIGHT} CHECK_FLAG;
class Obstacle:public QGraphicsObject
{
//Q_OBJECT
public:
    Obstacle(qreal w,qreal h,const QPixmap &pixs,dinosaur *play,QGraphicsScene *scene,int During_time,int*flag_run,QGraphicsItem *parent = 0);
    QRectF boundingRect()const;
    QPainterPath shape()const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPropertyAnimation *anim_move;
    int k_step;
    int k_flag;
protected:
    void advance(int step) ;
//signals:
    //void delt();
private:
    QPixmap O_Pix;
    qreal w;
    qreal h;
    dinosaur *o_play;
    int *the_flag;
    void     slt_eimt_del();
protected slots:

};

#endif // OBSTACLE

