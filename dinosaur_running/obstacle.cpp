#include "obstacle.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
Obstacle::Obstacle()
{
    speed=30;
    exist=1;

}
void Obstacle::advance(int step)
{

}

QRectF Obstacle::boundingRect()
{

}

void Obstacle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   painter->drawPixmap(0,0,50,90,QPixmap(":/new/obstacle.png"));
}

QPainterPath Obstacle::shape()
{

}
