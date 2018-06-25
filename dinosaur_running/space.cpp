#include "space.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsItem>
#include <dinosaur.h>

//游戏常数
#include "global.h"

Space::Space(QWidget *parent) : QGraphicsView(parent), isRunning(false) {

     m_max=0;
    //初始化场景
    m_scene = new QGraphicsScene;
    m_scene->setSceneRect(0,0,SCENEWIDTH,SCENEHEIGHT);
    setScene(m_scene);
    //初始化模式
   // setWindowFlags(Qt::FramelessWindowHint);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
  //  setOptimizationFlags(QGraphicsView::DontClipPainter | QGraphicsView::DontSavePainterState);
    setRenderHint(QPainter::Antialiasing);

    QPixmap pix(SCENEWIDTH, SCENEHEIGHT);
    pix.load(back_ground);
    QPixmap temp = pix.scaled(SCENEWIDTH, SCENEHEIGHT, Qt::KeepAspectRatioByExpanding);
    setBackgroundBrush(temp);

    //设置标题和窗口大小
    setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Dinosaur_running"));
    setFixedSize(SCENEWIDTH+20,SCENEHEIGHT+20);


    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(slt_updata()));
    //
  /*  connect(m_obstacle1,SIGNAL(delt()),this,SLOT(slt_del()));*/

    init();



}
void Space::init()
{
    //qDebug()<<"YES!";
    m_scores=0;
    m_step=0;
    r_step=0;
    run_flag=1;
    res=0;
    res1=0;
    QPixmap t;
    dur_time=2600;
    t=QPixmap(Dino_Pic);
    m_player = new dinosaur(D_Pos_X,D_Pos_Y,t,m_scene);
    res1=a.creat(0,3);
    if(res1==0)
    {
    t=QPixmap(Obs_Pic);
    m_obstacle1= new Obstacle(O_Pos_X,O_Pos_Y+30,t,m_player,m_scene,dur_time,&run_flag);
    }
    if(res1==1)
    {
    t=QPixmap(Obs_Pic_1);
    m_obstacle1= new Obstacle(O_Pos_X,O_Pos_Y,t,m_player,m_scene,dur_time,&run_flag);
    }
    if(res1==2)
    {
    t=QPixmap(Obs_Pic_2);
    m_obstacle1= new Obstacle(O_Pos_X,O_Pos_Y,t,m_player,m_scene,dur_time,&run_flag);
    }
    if(res1==3)
    {
    t=QPixmap(Obs_Pic_3);
    m_obstacle1= new Obstacle(O_Pos_X,O_Pos_Y,t,m_player,m_scene,dur_time,&run_flag);
    }

    s_num = new Show_score(S_Pos_X,S_Pos_Y,&m_scores,m_scene);
    s_num_1 =new Show_score(50,S_Pos_Y,&m_max,m_scene);
    m_player->setFocus();
    connect(m_player,SIGNAL(dead()),this,SLOT(slt_playerDead()));
    connect(m_player,SIGNAL(renew()),this,SLOT(slt_newGame()));
    m_timer->start(50);
}


void Space::slt_newGame()
{
    m_scene->clear();
    init();
    m_timer->start(50);
    isRunning = true;
}

void Space::slt_playerDead()
{
    m_timer->stop();
    isRunning = false;
    run_flag = 0;
    m_obstacle1->anim_move->stop();
    s_num->process();
    if(m_max<m_scores)
    {
        m_max= m_scores;
    }

    //slt_newGame();
}

void Space::slt_updata()
{
    m_scene->advance();
    dur_time=600+(1000000/(500+m_scores));
    //qDebug()<<dur_time;
    m_step++;
    r_step++;
    if (r_step==1)
    {
        res=a.creat(16,50);
    }
    if(r_step==res)
    {
        QPixmap st;
        qDebug()<<a.creat(0,3);
        res1=a.creat(0,3);
        if(res1==0)
        {
        st=QPixmap(Obs_Pic);
        m_obstacle1= new Obstacle(O_Pos_X,O_Pos_Y+30,st,m_player,m_scene,dur_time,&run_flag);
        }
        if(res1==1)
        {
        st=QPixmap(Obs_Pic_1);
        m_obstacle1= new Obstacle(O_Pos_X,O_Pos_Y,st,m_player,m_scene,dur_time,&run_flag);
        }
        if(res1==2)
        {
        st=QPixmap(Obs_Pic_2);
        m_obstacle1= new Obstacle(O_Pos_X,O_Pos_Y,st,m_player,m_scene,dur_time,&run_flag);
        }
        if(res1==3)
        {
        st=QPixmap(Obs_Pic_3);
        m_obstacle1= new Obstacle(O_Pos_X,O_Pos_Y,st,m_player,m_scene,dur_time,&run_flag);
        }

         //m_obstacle1= new Obstacle(O_Pos_X,O_Pos_Y,t,m_scene);
         r_step=0;

    }
   // qDebug()<<m_step;
   // qDebug()<<r_step;
    if (m_step % 2 == 0 )
    {

         m_scores++;

    }

    if (m_step % 100 == 0)
    {
        m_step = 0;
    }
}

void Space::slt_del()
{
    delete m_obstacle1;;
}
