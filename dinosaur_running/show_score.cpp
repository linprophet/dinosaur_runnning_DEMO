#include "show_score.h"
#include "global.h"
#include <QGraphicsScene>
#include <QDebug>

Show_score::Show_score(qreal w,qreal h,int* score,QGraphicsScene *scene,QGraphicsItem *parent)
    :QGraphicsObject(parent)
{
    s_score = score;
    QPixmap temp;
    temp = QPixmap(Num_3_Pic);
    s_num_pic = temp;

    s_num_pic_bit[0]=temp;
    s_num_pic_bit[1]=temp;
    s_num_pic_bit[2]=temp;
    s_num_pic_bit[3]=temp;
    s_num_pic_bit[4]=temp;



    temp = QPixmap(Num_0_Pic);
    num[0]=temp;
    temp = QPixmap(Num_1_Pic);
    num[1]=temp;
    temp = QPixmap(Num_2_Pic);
    num[2]=temp;
    temp = QPixmap(Num_3_Pic);
    num[3]=temp;
    temp = QPixmap(Num_4_Pic);
    num[4]=temp;
    temp = QPixmap(Num_5_Pic);
    num[5]=temp;
    temp = QPixmap(Num_6_Pic);
    num[6]=temp;
    temp = QPixmap(Num_7_Pic);
    num[7]=temp;
    temp = QPixmap(Num_8_Pic);
    num[8]=temp;
    temp = QPixmap(Num_9_Pic);
    num[9]=temp;
    scene->addItem(this);
    setPos(w,h);
}


void Show_score::advance(int step)
{
    //个位
    qDebug()<<*s_score;
    /*
    bit=*s_score%10;
    num_address=int2string(bit);
    s_num_pic_bit[4]=QPixmap(num_address);
    //十位
    bit=*s_score/10%10;
    num_address=int2string(bit);
    s_num_pic_bit[3]=QPixmap(num_address);
    //百位
    bit=*s_score/100%10;
    num_address=int2string(bit);
    s_num_pic_bit[2]=QPixmap(num_address);
    //个位
    bit=*s_score/1000%10;
    num_address=int2string(bit);
    s_num_pic_bit[1]=QPixmap(num_address);
    //个位
    bit=*s_score/10000;
    num_address=int2string(bit);
    s_num_pic_bit[0]=QPixmap(num_address);
    */
    //个位

    bit=*s_score%10;
    s_num_pic_bit[4]=num[bit];
    //十位
    bit=*s_score/10%10;
    s_num_pic_bit[3]=num[bit];
    //百位
    bit=*s_score/100%10;
    s_num_pic_bit[2]=num[bit];
    //千位
    bit=*s_score/1000%10;
    s_num_pic_bit[1]=num[bit];
    //万位
    bit=*s_score/10000;
    s_num_pic_bit[0]=num[bit];
    update();
}

QRectF Show_score::boundingRect()const
{
  QRectF sqaue(0,0,500,50);
 return sqaue;
}

void Show_score::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   painter->drawPixmap(0,0,Num_H,Num_W,s_num_pic_bit[0]);
   painter->drawPixmap(Interval,0,Num_H,Num_W,s_num_pic_bit[1]);
   painter->drawPixmap(Interval*2,0,Num_H,Num_W,s_num_pic_bit[2]);
   painter->drawPixmap(Interval*3,0,Num_H,Num_W,s_num_pic_bit[3]);
   painter->drawPixmap(Interval*4,0,Num_H,Num_W,s_num_pic_bit[4]);
}



QPainterPath Show_score::shape()const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Show_score::process()
{
    ;
}
/*
QString Show_score::int2string(int a)
{
    if(a==0)
    {
        return Num_0_Pic;
    }
    if(a==1)
    {
        return Num_1_Pic;
    }
    if(a==2)
    {
        return Num_2_Pic;
    }
    if(a==3)
    {
        return Num_3_Pic;
    }
    if(a==4)
    {
        return Num_4_Pic;
    }
    if(a==5)
    {
        return Num_5_Pic;
    }
    if(a==6)
    {
        return Num_6_Pic;
    }
    if(a==7)
    {
        return Num_7_Pic;
    }
    if(a==8)
    {
        return Num_8_Pic;
    }
    if(a==9)
    {
        return Num_9_Pic;
    }
}
*/
