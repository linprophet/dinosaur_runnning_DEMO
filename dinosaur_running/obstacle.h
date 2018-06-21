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
#include <QPoint>

typedef enum {UP, DOWN, LEFT, RIGHT} CHECK_FLAG;
class Obstacle:public QGraphicsObject
{
//Q_OBJECT
public:
    Obstacle(qreal w,qreal h,const QPixmap &pixs,QGraphicsScene *scene,QGraphicsItem *parent = 0);
    QRectF boundingRect()const;
    QPainterPath shape()const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPropertyAnimation *anim_move;
protected:
    void advance(int step) ;
//signals:
    //void delt();
private:
    QPixmap O_Pix;
    qreal w;
    qreal h;
protected slots:
    void     slt_eimt_del();
};

#endif // OBSTACLE

