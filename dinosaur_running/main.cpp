#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QWidget>
#include <QIcon>
#include <QPixmap>
#include "obstacle.h"
#include "space.h"
#include "Randomizer.h"
#include "dinosaur.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Space space;
    //设置Icon
    a.setWindowIcon(QIcon(":/new/icon_1.png"));
    space.show();
    return a.exec();
}
