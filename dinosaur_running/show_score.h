#ifndef SHOW_SCORE
#define SHOW_SCORE
#include <QGraphicsObject>
#include <QPixmap>
#include <QApplication>
#include <QGraphicsObject>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QPainter>
#include <QString>

class Show_score:public QGraphicsObject

{
public:
    Show_score(qreal w,qreal h,int* score,QGraphicsScene *scene,QGraphicsItem *parent = 0);
    QRectF boundingRect()const;
    QPainterPath shape()const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void process();
protected:
    void advance(int step) ;
private:
    int* s_score;
    QPixmap s_num_pic,s_num_pic_bit[5];
    QPixmap num[10];
    //QString int2string(int a);
    int bit;
    QString num_address;
};

#endif // SHOW_SCORE

