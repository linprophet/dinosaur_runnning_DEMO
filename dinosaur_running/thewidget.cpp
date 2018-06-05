#include "thewidget.h"
#include "ui_thewidget.h"
#include <QPainter>

TheWidget::TheWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TheWidget)
{
    ui->setupUi(this);
    this->setFixedSize(2500,1000);
}

TheWidget::~TheWidget()
{
    delete ui;
}

void TheWidget::paintEvent(QPaintEvent *)
{
    QPainter p;
    p.begin(this);
    p.drawPixmap(0,0,width(),height(),QPixmap("../source/c++ project_backgruond.png"));
    p.end();
}
