#ifndef GAME_H
#define GAME_H
#define _USE_MATH_DEFINES

#include <QMainWindow>
#include<QLabel>
#include<QWidget>
#include<QPushButton>
#include<QLCDNumber>
#include<QTime>
#include<ctime>
#include<QPixmap>
#include<QKeyEvent>
#include<cstdio>
#include<cmath>
#include<fstream>


namespace Ui {
class game;
}
using namespace std;
class game : public QMainWindow
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = 0);
    ~game();
    void sleep(unsigned int msec);
    void up();
    void down();
    void left();
    void right();
    void newnum();
    void scorechange(int);
    bool isfill();
    bool isgameover();
    void movelab(int ,int,int,int);
    void labcombine(int,int,int ,int,int);
    void keyPressEvent(QKeyEvent* );
    void newlab(int ,int,int);

    void clockwise();
    void counterclockwise();
    void checkbest();

private slots:
    void restartgame();
    void xswitch();

private:
    Ui::game *ui;
    int number[4][4];
    int score;
    QLabel *lab[4][4];
    int ok;
    QLabel *gameover;
    int xsw;
    int temnumber[4][4];
    QLabel *temlab[4][4];
    int best;



};

#endif // GAME_H
