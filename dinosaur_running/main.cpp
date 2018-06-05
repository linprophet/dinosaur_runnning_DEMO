#include "thewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TheWidget w;
    w.show();

    return a.exec();
}
