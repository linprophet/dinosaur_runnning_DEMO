#ifndef THEWIDGET_H
#define THEWIDGET_H

#include <QWidget>
#include <ui_thewidget.h>
#include <QPainter>

namespace Ui {
class TheWidget;
}

class TheWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TheWidget(QWidget *parent = 0);
    ~TheWidget();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::TheWidget *ui;

};

#endif // THEWIDGET_H
