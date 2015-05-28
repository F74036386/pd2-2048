#ifndef GAME_H
#define GAME_H

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


namespace Ui {
class game;
}

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
    void output();

private slots:
    void restartgame();


private:
    Ui::game *ui;
    int number[4][4];
    int score;
    QLabel *lab[4][4];
    int ok;
    QLabel *gameover;

};

#endif // GAME_H
