#ifndef SPACE_H
#define SPACE_H


#include "obstacle.h"
#include "Randomizer.h"
#include "dinosaur.h"
#include "show_score.h"
#include <QTime>
#include <QWidget>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsItem>

class Space : public QGraphicsView
{
    Q_OBJECT
public:
    Space(QWidget *parent = 0);
    void init();
    Show_score *s_num;
    //void enemys();
protected:
    //void mouseDoubleClickEvent(QMouseEvent *event);
private:
    QGraphicsScene *m_scene;
    QTimer *m_timer;
    dinosaur *m_player;
    Obstacle *m_obstacle1;
    Obstacle *m_obstacle2;
    int m_scores , m_step;
    bool isRunning;
signals:
    //void sig_menu();

protected slots:
    void slt_newGame();
    void slt_playerDead();
    //void slt_startGame();
    //void slt_pauseGame();
    void slt_updata();
    void slt_del();
    //void slt_addscore(int);
    //void slt_menu();
};
#endif // SPACE_H
