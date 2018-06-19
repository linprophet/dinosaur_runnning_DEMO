#ifndef OBSTACLE
#define OBSTACLE
#include <QApplication>
#include <QGraphicsObject>
#include <QPixmap>
#include <QPropertyAnimation>

typedef enum {UP, DOWN, LEFT, RIGHT} CHECK_FLAG;
class Obstacle:public QGraphicsObject
{

public:
    Obstacle(qreal w,qreal h,const QPixmap &pixs,QGraphicsScene *scene,QGraphicsItem *parent = 0);
    QRectF boundingRect()const;
    QPainterPath shape()const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPropertyAnimation *anim_move;
protected:
    void advance(int step) ;
private:
    QPixmap O_Pix;
    qreal w;
    qreal h;
};

#endif // OBSTACLE

