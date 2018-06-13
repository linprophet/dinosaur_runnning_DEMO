#ifndef OBSTACLE
#define OBSTACLE
#include <QApplication>
#include <QGraphicsObject>
#include <QPixmap>

typedef enum {UP, DOWN, LEFT, RIGHT} CHECK_FLAG;
class Obstacle:public QGraphicsObject
{

public:
    Obstacle();
    QRectF boundingRect();
    QPainterPath shape() ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;
protected:
    void advance(int step) ;
private:
    qreal speed;
    bool exist;
};

#endif // OBSTACLE

