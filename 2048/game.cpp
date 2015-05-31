#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game)
{
     ui->setupUi(this);
     QPixmap x(":/new/prefix1/2048  pit/2048logo.png");
      ui->label_2->setPixmap(x);
       ui->label_2->setGeometry(30,25,200,100);
      ui->label_2->show();


    score=6;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            number[i][j]=0;
            lab[i][j]=NULL;
        }

    }
connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(restartgame()));
connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(xswitch()));
gameover=NULL;
xsw=0;
best=0;
checkbest();
restartgame();

}

game::~game()
{
    delete ui;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            delete lab[i][j];
        }
    delete gameover;
}

void game::keyPressEvent(QKeyEvent* event){    //to know the key press
if(isgameover()){
    if(gameover==NULL){
gameover=new QLabel(this);
    QPixmap x(":/new/prefix1/2048  pit/GAMEOVER.png");
   gameover->setPixmap(x);
    gameover->setGeometry(0,200,600,300);
   gameover->show();
}
}
if(ok!=0)return;
ok=1;
    switch(event->key()){
    case Qt::Key_Up:{
            up();
            break;
}
    case  Qt::Key_Down:{
    down();
    break;
}
    case Qt::Key_Right:{
            right();
     break;
}
    case Qt::Key_Left:{
        left();
        break;
}
    case Qt::Key_X:{
        clockwise();
           sleep(300);
        down();

        break;
    }
    case Qt::Key_Z:{
            counterclockwise();
            sleep(300);
            down();
            break;
        }
    }

ok=0;
sleep(300);
}


void game::up(){   // to move up
    int flag=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(number[j][i]!=0){
               for(int k=1;k<4-j;k++){
                  if(number[j+k][i]!=0){
                     if(number[j+k][i]==number[j][i]){
                         number[j][i]+=number[j+k][i];
                         number[j+k][i]=0;
                         labcombine(j+k,i,j,i,number[j][i]);
                         flag++;
                         scorechange(number[j][i]);

                     }

                 break;
                  }
                }
            }
            else{
                for(int k=1;k<4-j;k++){
                    if(number[j+k][i]!=0){
                          number[j][i]=number[j+k][i];
                          number[j+k][i]=0;
                              movelab(j+k,i,j,i);
                              flag++;
                              j--;


                        break;
                    }

                  }

           }
       }
   }
        if(flag!=0)
            newnum();


}

void game:: down(){  //to move down
    int flag=0;
    for(int i=0;i<4;i++){
        for(int j=3;j>0;j--){
            if(number[j][i]!=0){
               for(int k=1;k<=j;k++){
                   if(j==0)break;
                  if(number[j-k][i]!=0){
                     if(number[j-k][i]==number[j][i]){
                         number[j][i]+=number[j-k][i];
                         labcombine(j-k,i,j,i,number[j][i]);
                          number[j-k][i]=0;
                         flag++;
                         scorechange(number[j][i]);

                       }

                 break;
                  }
                }
            }
            else{
                for(int k=1;k<=j;k++){
                    if(number[j-k][i]!=0){
                          number[j][i]=number[j-k][i];
                          number[j-k][i]=0;
                              movelab(j-k,i,j,i);
                              flag++;
                              j++;


                        break;
                    }

                  }

           }
       }
   }
        if(flag!=0)
            newnum();


}
void game:: left(){// to move left
    int flag=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(number[i][j]!=0){
               for(int k=1;k<4-j;k++){
                  if(number[i][j+k]!=0){
                     if(number[i][j+k]==number[i][j]){
                         number[i][j]+=number[i][j+k];
                          number[i][j+k]=0;
                         labcombine(i,j+k,i,j,number[i][j]);
                         flag++;
                         scorechange(number[i][j]);

                       }

                 break;
                  }
                }
            }
            else{
                for(int k=1;k<4-j;k++){
                    if(number[i][j+k]!=0){
                          number[i][j]=number[i][j+k];
                          number[i][j+k]=0;
                              movelab(i,j+k,i,j);
                              flag++;
                              j--;


                        break;
                    }

                  }

           }
       }
   }
        if(flag!=0)
            newnum();



}

void game:: right(){          // move right
    int flag=0;
    for(int i=0;i<4;i++){
        for(int j=3;j>0;j--){
            if(number[i][j]!=0){
               for(int k=1;k<=j;k++){
                  if(number[i][j-k]!=0){
                     if(number[i][j-k]==number[i][j]){
                         number[i][j]+=number[i][j-k];
                         number[i][j-k]=0;
                         labcombine(i,j-k,i,j,number[i][j]);
                         flag++;
                         scorechange(number[i][j]);

                       }
                   }
                 break;
                }
            }
            else{
                for(int k=1;k<=j;k++){
                    if(number[i][j-k]!=0){
                          number[i][j]=number[i][j-k];
                          number[i][j-k]=0;
                              movelab(i,j-k,i,j);
                              flag++;
                              j++;


                        break;
                    }

                  }

           }
       }
   }
        if(flag!=0)
            newnum();


}
void game::labcombine(int yfrom,int xfrom,int yterget,int xterget,int num){     // to combin the label

   for(int k=1;k<=110;k++){
   //lab[yterget][xterget]->setGeometry(100+xterget*110,150+yterget*110,100,100);
   lab[yfrom][xfrom]->setGeometry(100+xfrom*110+k*(xterget-xfrom),150+yfrom*110+k*(yterget-yfrom),100,100);
       lab[yfrom][xfrom]->show();
       sleep(2);
}
    delete lab[yfrom][xfrom];
   delete lab[yterget][xterget];
   newlab(yterget,xterget,num);
    lab[yfrom][xfrom]=new QLabel(this);
    QPixmap x(":/new/prefix1/2048  pit/0.png");
    lab[yfrom][xfrom]->setPixmap(x);
    lab[yfrom][xfrom]->setGeometry(100+xfrom*110,150+yfrom*110,100,100);
   lab[yfrom][xfrom]->show();

}

void game::movelab(int yfrom,int xfrom,int yterget,int xterget){     //to move the labels
    delete lab[yterget][xterget];
    lab[yterget][xterget]=lab[yfrom][xfrom];
    for(int k=1;k<=110;k++){
    //lab[yterget][xterget]->setGeometry(100+xterget*110,150+yterget*110,100,100);
    lab[yterget][xterget]->setGeometry(100+xfrom*110+k*(xterget-xfrom),150+yfrom*110+k*(yterget-yfrom),100,100);
        lab[yterget][xterget]->show();
        sleep(2);
}

    lab[yfrom][xfrom]=new QLabel(this);
    QPixmap x(":/new/prefix1/2048  pit/0.png");
    lab[yfrom][xfrom]->setPixmap(x);
    lab[yfrom][xfrom]->setGeometry(100+xfrom*110,150+yfrom*110,100,100);
   lab[yfrom][xfrom]->show();
}

bool game::isfill(){            // to know the block is fill or not
   int a=0;
   for(int i=0;i<4;i++){
       for(int j=0;j<4;j++){
           if(number[i][j]!=0)
               a++;
       }
   }
    if(a>=16)return 1;
    else return 0;
}


bool game::isgameover(){           //to know is gameover or not
    if(!isfill())return 0;
    int flag=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i!=0){
                if(number[i][j]==number[i-1][j])
                    flag++;
            }
            if(i!=3){
                if(number[i][j]==number[i+1][j])
                    flag++;
            }
            if(j!=0){
                if(number[i][j]==number[i][j-1])
                    flag++;
            }
            if(j!=3){
                if(number[i][j]==number[i][j+1])
                    flag++;
            }


        }

    }
    if(flag==0)return 1;
    else return 0;
}
void game::newlab(int a,int b,int num){     // use to new a label which have the pixmap need to use
    lab[a][b]=new QLabel(this);
    switch(num){
    case 0:{
        QPixmap x(":/new/prefix1/2048  pit/0.png");
        lab[a][b]->setPixmap(x);
        lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
        lab[a][b]->show();
        break;
}
    case 2:{
        QPixmap x(":/new/prefix1/2048  pit/2.png");
        lab[a][b]->setPixmap(x);
        lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
        lab[a][b]->show();
        break;
}
    case 4:{
        QPixmap x(":/new/prefix1/2048  pit/4.png");
        lab[a][b]->setPixmap(x);
       lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
        lab[a][b]->show();
        break;
}
    case 8:{
        QPixmap x(":/new/prefix1/2048  pit/8.png");
        lab[a][b]->setPixmap(x);
        lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
        lab[a][b]->show();
        break;
}
    case 16:{
        QPixmap x(":/new/prefix1/2048  pit/16.png");
        lab[a][b]->setPixmap(x);
         lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
        lab[a][b]->show();
        break;
}
    case 32:
  {      QPixmap x(":/new/prefix1/2048  pit/32.png");
        lab[a][b]->setPixmap(x);
         lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
        lab[a][b]->show();
        break;
}
    case 64:
 {       QPixmap x(":/new/prefix1/2048  pit/64.png");
        lab[a][b]->setPixmap(x);
        lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
        lab[a][b]->show();
        break;
}
 {   case 128:
        QPixmap x(":/new/prefix1/2048  pit/128.png");
        lab[a][b]->setPixmap(x);
       lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
        lab[a][b]->show();
        break;
}
    case 256:
 {       QPixmap x(":/new/prefix1/2048  pit/256.png");
        lab[a][b]->setPixmap(x);
         lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
        lab[a][b]->show();
        break;
  }  case 512:
   {     QPixmap x(":/new/prefix1/2048  pit/512.png");
        lab[a][b]->setPixmap(x);
        lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
        lab[a][b]->show();
        break;
}
    case 1024:
 {       QPixmap x(":/new/prefix1/2048  pit/1024.png");
        lab[a][b]->setPixmap(x);
       lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
        lab[a][b]->show();
        break;
  }  case 2048:
   {     QPixmap x(":/new/prefix1/2048  pit/2048.png");
        lab[a][b]->setPixmap(x);
       lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
        lab[a][b]->show();
        break;
    }case 4096:
     {   QPixmap x(":/new/prefix1/2048  pit/4096.png");
        lab[a][b]->setPixmap(x);
        lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
        lab[a][b]->show();
        break;
    }case 8192:
     {   QPixmap x(":/new/prefix1/2048  pit/8192.png");
        lab[a][b]->setPixmap(x);
        lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
        lab[a][b]->show();
        break;
    }
    default:{
        QPixmap x(":/new/prefix1/2048  pit/8192.png");
                lab[a][b]->setPixmap(x);
                 lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
                lab[a][b]->show();
                break;
            }
    }
}

void game:: newnum(){      //use to make new number block
    if(isfill())return;
    srand((unsigned)time(NULL)+rand());

    int a=rand()%4;
    int b=rand()%4;
    int c=rand()%2+1;
    while(number[a][b]!=0){
        a=rand()%4;
        b=rand()%4;
    }
    number[a][b]=c*2;
    delete lab[a][b];
    lab[a][b]=new QLabel(this);
    if(c==1){

    QPixmap x(":/new/prefix1/2048  pit/2.png");
    lab[a][b]->setPixmap(x);
    lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
   lab[a][b]->show();
    }
    else{
     QPixmap x(":/new/prefix1/2048  pit/4.png");

    lab[a][b]->setPixmap(x);
    lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
   lab[a][b]->show();
    }

}

void game:: scorechange(int num){   // use to change the score
    score+=num;
    ui->lcdNumber->display(score);
    checkbest();

}

void game:: restartgame(){          // use to restart game
    if(gameover!=NULL){
        gameover->close();
        delete gameover;
        gameover=NULL;
    }
    score=0;
    ok=0;
    xsw=0;
    ui->lcdNumber->display(score);
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
          if(lab[i][j]!=NULL)
              delete lab[i][j];
            number[i][j]=0;
            lab[i][j]= new QLabel(this);
            QPixmap x(":/new/prefix1/2048  pit/0.png");
            lab[i][j]->setPixmap(x);
            lab[i][j]->setGeometry(100+j*110,150+i*110,100,100);
           lab[i][j]->show();
        }
   }
   newnum();

}


/*void game::output(){                   //used to debug
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            printf("%d ",number[i][j]);
        printf("\n");
    }
    printf("\n");
}*/

void game::sleep(unsigned int msec)       // use to  delay the time
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void game::xswitch(){            //  to switch the X block
    if(xsw==0){
        if(isfill())return;
        srand((unsigned)time(NULL)+rand());
        sleep(100);
        int a=rand()%4;
        int b=rand()%4;
        while(number[a][b]!=0){
            a=rand()%4;
            b=rand()%4;
        }
        number[a][b]=1;
        delete lab[a][b];
        lab[a][b]=new QLabel(this);


        QPixmap x(":/new/prefix1/2048  pit/x.png");
        lab[a][b]->setPixmap(x);
        lab[a][b]->setGeometry(100+b*110,150+a*110,100,100);
       lab[a][b]->show();
       xsw=1;

    }

    else{
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(number[i][j]==1){
                    number[i][j]=0;
                    delete lab[i][j];
                    lab[i][j]=new QLabel(this);


                    QPixmap x(":/new/prefix1/2048  pit/0.png");
                    lab[i][j]->setPixmap(x);
                    lab[i][j]->setGeometry(100+j*110,150+i*110,100,100);
                   lab[i][j]->show();
                   xsw=0;
                }
            }
        }

    }

}

void game::clockwise(){          // to move the block for clockwise rotate
    for(int a=0;a<4;a++){
        for(int b=0;b<4;b++){
            temnumber[a][b]=number[a][b];
            temlab[a][b]=lab[a][b];
        }
    }
    for(double n=0;n<12;n++){
           double k=(0.5)*(n*0.1)* M_PI;
        for(int a=0;a<4;a++){
            for(int b=0;b<4;b++){
                double xway=(110*b-155)*cos((double)k)-(110*a-90)*sin((double) k)+255;
                double yway=(110*b-155)*sin((double)k)+(110*a-90)*cos((double) k)+240;
               lab[a][b]->setGeometry(xway,yway,100,100);

            }
        }
         sleep(50);
    }
      for(int i=0;i<4;i++){
          for(int j=0;j<4;j++){
              number[i][j]=temnumber[3-j][i];
              lab[i][j]=temlab[3-j][i];
              lab[i][j]->setGeometry(110*j+100,110*i+150,100,100);
              lab[i][j]->show();
          }
      }

}

void game::counterclockwise(){      // to move the block for counterclockwise rotate
    for(int a=0;a<4;a++){
        for(int b=0;b<4;b++){
            temnumber[a][b]=number[a][b];
            temlab[a][b]=lab[a][b];
        }
    }
    for(double n=0;n>-12;n--){
          double k=(0.5)*(n*0.1)* M_PI;
        for(int a=0;a<4;a++){
            for(int b=0;b<4;b++){
                double xway=(110*b-155)*cos((double)k)-(110*a-90)*sin((double) k)+255;
                double yway=(110*b-155)*sin((double)k)+(110*a-90)*cos((double) k)+240;
               lab[a][b]->setGeometry(xway,yway,100,100);

            }
        }
         sleep(50);
    }
      for(int i=0;i<4;i++){
          for(int j=0;j<4;j++){
              number[i][j]=temnumber[j][3-i];
              lab[i][j]=temlab[j][3-i];
              lab[i][j]->setGeometry(110*j+100,110*i+150,100,100);
              lab[i][j]->show();
          }
      }

}

  void game:: checkbest(){            //  use open file to check best score
      ifstream fin;
      fin.open("best.txt", ios::in);

      if(!fin){
          best=score;
           ui->lcdNumber_2->display(best);
            fin.close();
           ofstream fout;
           fout.open("best.txt",ios::out);
           if(!fout){
               return;
           }
           fout<<best;
           fout.close();

      }
      else{
      fin>>best;
      fin.close();

      if(score>best){
          best=score;
           ui->lcdNumber_2->display(best);
          ofstream fout;
          fout.open("best.txt",ios::out);
          if(!fout){
              ui->lcdNumber_2->display(best);
              return;
          }
          fout<<best;
          fout.close();
      }

         ui->lcdNumber_2->display(best);
   }


  }
