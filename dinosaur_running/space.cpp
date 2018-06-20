#include "space.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsItem>
#include <dinosaur.h>

//游戏常数
#include "global.h"

Space::Space(QWidget *parent) : QGraphicsView(parent), isRunning(false) {

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
    pix.load(background);
    QPixmap temp = pix.scaled(SCENEWIDTH, SCENEHEIGHT, Qt::KeepAspectRatioByExpanding);
    setBackgroundBrush(temp);

    //设置标题和窗口大小
    setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Dinosaur_running"));
    setFixedSize(SCENEWIDTH+20,SCENEHEIGHT+20);


    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(slt_updata()));
    //connect(this, SIGNAL(sig_menu()), this, SLOT(slt_menu()));

    init();



}
void Space::init()
{
    //qDebug()<<"YES!";
    m_scores=0;
    m_step=0;
    QPixmap t;
    t=QPixmap(Dino_Pic);
    m_player = new dinosaur(D_Pos_X,D_Pos_Y,t,m_scene);
    t=QPixmap(Obs_Pic);
    m_obstacle1= new Obstacle(O_Pos_X,O_Pos_Y,t,m_scene);
    s_num = new Show_score(S_Pos_X,S_Pos_Y,&m_scores,m_scene);
    m_player->setFocus();
    connect(m_player,SIGNAL(dead()),this,SLOT(slt_playerDead()));
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
    m_obstacle1->anim_move->stop();
    s_num->process();
    //slt_newGame();
}

void Space::slt_updata()
{
    m_scene->advance();
    m_step++;
    if (m_step % 2 == 0 )
    {

         m_scores++;

    }

    if (m_step % 500 == 0)
    {
        m_step = 0;
        //delete m_obstacle1;
    }
}
