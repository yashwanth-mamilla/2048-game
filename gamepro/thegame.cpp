#include "thegame.h"
#include "ui_thegame.h"
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <QPixmap>
#include <QKeyEvent>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QStack>
#include <QSound>
#include <QFile>

bool ff11=false;
QSound pop("/home/yashwanth/Projects/gamepro/pop.mp3");
class Config{
public:
    int B[4][4];
    bool stat;
    bool movement;
    int score;
    int highscore;
    bool ff;
};
Config config;
QStack< Config > cstack;
void setConfig(int board[][4],bool Stat,bool Movement,int Score,int Highscore,bool flag)
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            config.B[i][j]=board[i][j];
    config.stat=Stat;
    config.movement=Movement;
    config.score=Score;
    config.highscore=Highscore;
    config.ff=flag;
}
void thegame::setscore(int score){
    std::stringstream s;
    s << score ;
    std::string a=s.str();
    QString ss =QString::fromStdString(a);
    ui->label->setText(ss);

    if(score>highscore){
        ui->highscorelabel->setText(ss);
        highscore=score;
    }

    QString sk="Undo";
            //sk=sk+QString::number(cstack.size());

    ui->undobutton->setText(sk);
    ui->undobutton->setStyleSheet("background: rgb( 245, 176, 65 );color: rgb(119,110,101); font: bold;font: 15pt;border-color: rgb(220, 118, 51);border-width:2.5px;border-style:outset;");
    if(cstack.size()==0)
    {
        ui->undobutton->setStyleSheet("background: rgb( 245, 176, 65 );color: rgb(119,110,101); font: bold;font: 15pt;");
    }

}
void thegame::randomizer(bool status,bool m){
    if(!m)
        return;
    if(status==false)
    {
        int i,j;
        i=rand()%4;
        j=rand()%4;
        while(Board[i][j]!=0)
        {
            i=rand()%4;
            j=rand()%4;
        }
        Board[i][j]=2;
        movement=false;
    }
}
bool thegame::checkBoard(){
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(Board[i][j]==0)
                return false;
        }
    }
    return true;
}
void thegame::checkwin(){
    qDebug()<<" ff "<<ff<<endl;
    if(ff11==true)
        return;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(Board[i][j]==2048)
            {
                //hide();
                qDebug()<< "win "<<ff11<<endl;
                gwin=new gamewin(this);

                gwin->show();
                ff=true;
                ff11=true;
                return ;
            }
        }
    }
}
bool thegame::completeboard(){

    for(int i=0;i<3;i++)
    {
        for(int j=1;j<4;j++)
        {
            if(Board[i][j-1]==Board[i][j])
                return false;
            if(Board[i][j]==Board[i+1][j])
                return false;
        }
    }
    for(int i=0;i<3;i++)
    {
        if(Board[i][0]==Board[i+1][0])
        return false;
        if(Board[3][i]==Board[3][i+1])
        return false;
    }
    qDebug()<< true;
    return true;

}
void thegame::Newgame(){
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            Board[i][j]=0;
        }
    }
    score=0;
}
void thegame::update(QKeyEvent* event)
{
        if(event->key()==Qt::Key_A)
        {
            pop.play();
            setConfig(Board,stat,movement,score,0,ff);

            for(int i=0;i<4;i++)
            {
                for(int j=3;j>0;j--)
                {
                    if(Board[i][j-1]==0 && Board[i][j]!=0)
                    {
                        Board[i][j-1]=Board[i][j];
                        Board[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=3;j>0;j--)
                {
                    if(Board[i][j-1]==0 && Board[i][j]!=0)
                    {
                        Board[i][j-1]=Board[i][j];
                        Board[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=3;j>0;j--)
                {
                    if(Board[i][j-1]==0 && Board[i][j]!=0)
                    {
                        Board[i][j-1]=Board[i][j];
                        Board[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<3;j++)
                {
                    if(Board[i][j+1]==Board[i][j] && Board[i][j]!=0)
                    {
                        score+= Board[i][j];
                        Board[i][j] *= 2;
                        Board[i][j+1]=0;
                        movement=true;

                    }
                }
                for(int j=3;j>0;j--)
                {
                    if(Board[i][j-1]==0 && Board[i][j]!=0)
                    {
                        Board[i][j-1]=Board[i][j];
                        Board[i][j]=0;
                    }
                }
                for(int j=3;j>0;j--)
                {
                    if(Board[i][j-1]==0 && Board[i][j]!=0)
                    {
                        Board[i][j-1]=Board[i][j];
                        Board[i][j]=0;
                    }
                }
            }
            if(movement)
            {
                if(cstack.size()<5)
                cstack.push_back(config);
               else if(cstack.size()>=5)
                {
                    cstack.pop_front();
                    cstack.push_back(config);
                }
            }
            setscore(score);
            stat=checkBoard();
            randomizer(stat,movement);
            setpics();
            checkwin();
             qDebug()<< "stat = " << stat << " mov = "<< movement << " ff = "<< ff<<endl;
            thegame::stat=thegame::checkBoard();
            if(stat){
                if(thegame::completeboard())
                {
                    scorefile();
                    saveHighscores();
                    cstack.clear();
                    savegame();
                    hide();
                    gover=new Gameover(this);
                    gover->show();

                }
            }
        }
        if(event->key()==Qt::Key_D)
        {
            pop.play();
            setConfig(Board,stat,movement,score,0,ff);


            for(int i=0;i<4;i++)
            {
                for(int j=0;j<3;j++)
                {
                    if(Board[i][j+1]==0 && Board[i][j]!=0)
                    {
                        Board[i][j+1]=Board[i][j];
                        Board[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<3;j++)
                {
                    if(Board[i][j+1]==0 && Board[i][j]!=0)
                    {
                        Board[i][j+1]=Board[i][j];
                        Board[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<3;j++)
                {
                    if(Board[i][j+1]==0 && Board[i][j]!=0)
                    {
                        Board[i][j+1]=Board[i][j];
                        Board[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=3;j>0;j--)
                {
                    if(Board[i][j-1]==Board[i][j] && Board[i][j]!=0)
                    {
                        score+=Board[i][j-1];
                        Board[i][j] *= 2;
                        Board[i][j-1]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<3;j++)
                {
                    if(Board[i][j+1]==0 && Board[i][j]!=0)
                    {
                        Board[i][j+1]=Board[i][j];
                        Board[i][j]=0;
                    }
                }
                for(int j=0;j<3;j++)
                {
                    if(Board[i][j+1]==0 && Board[i][j]!=0)
                    {
                        Board[i][j+1]=Board[i][j];
                        Board[i][j]=0;
                    }
                }
            }
            if(movement){
                if(cstack.size()<5)
                cstack.push_back(config);
                else if(cstack.size()>=5)
                {
                    cstack.pop_front();
                    cstack.push_back(config);
                }
            }
            setscore(score);
            stat=checkBoard();
            randomizer(stat,movement);
            setpics();
            checkwin();
             qDebug()<< "stat = " << stat << " mov = "<< movement << " ff = "<< ff<<endl;
            thegame::stat=thegame::checkBoard();
            if(stat){
                if(thegame::completeboard())
                {
                    scorefile();
                    saveHighscores();
                    cstack.clear();
                    savegame();
                    hide();
                    gover=new Gameover(this);
                    gover->show();

                }
            }
        }
        if(event->key()==Qt::Key_W)
        {
            pop.play();
            setConfig(Board,stat,movement,score,0,ff);


            for(int i=0;i<4;i++){
                for(int j=3;j>0;j--)
                {
                    if(Board[j-1][i]==0 && Board[j][i]!=0)
                    {
                        Board[j-1][i]=Board[j][i];
                        Board[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=3;j>0;j--)
                {
                    if(Board[j-1][i]==0 && Board[j][i]!=0)
                    {
                        Board[j-1][i]=Board[j][i];
                        Board[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=3;j>0;j--)
                {
                    if(Board[j-1][i]==0 && Board[j][i]!=0)
                    {
                        Board[j-1][i]=Board[j][i];
                        Board[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<3;j++)
                {
                    if(Board[j+1][i]==Board[j][i] && Board[j][i]!=0)
                    {
                        score+=Board[j][i];
                        Board[j][i] *= 2;
                        Board[j+1][i]=0;
                        movement=true;
                    }
                }
                for(int j=3;j>0;j--)
                {
                    if(Board[j-1][i]==0 && Board[j][i]!=0)
                    {
                        Board[j-1][i]=Board[j][i];
                        Board[j][i]=0;
                    }
                }
                for(int j=3;j>0;j--)
                {
                    if(Board[j-1][i]==0 && Board[j][i]!=0)
                    {
                        Board[j-1][i]=Board[j][i];
                        Board[j][i]=0;
                    }
                }
            }
            if(movement){
                if(cstack.size()<5)
                cstack.push_back(config);
                else if(cstack.size()>=5)
                {
                    cstack.pop_front();
                    cstack.push_back(config);
                }
            }
            setscore(score);
            stat=checkBoard();
            randomizer(stat,movement);
            setpics();
            checkwin();
             qDebug()<< "stat = " << stat << " mov = "<< movement << " ff = "<< ff<<endl;
            thegame::stat=thegame::checkBoard();
            if(stat){
                if(thegame::completeboard())
                {
                    scorefile();
                    saveHighscores();
                    cstack.clear();
                    savegame();
                    hide();
                    gover=new Gameover(this);
                    gover->show();

                }
            }
        }
        if(event->key()==Qt::Key_S)
        {
            pop.play();
            setConfig(Board,stat,movement,score,0,ff);


            for(int i=0;i<4;i++){
                for(int j=0;j<3;j++)
                {
                    if(Board[j+1][i]==0 && Board[j][i]!=0)
                    {
                        Board[j+1][i]=Board[j][i];
                        Board[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<3;j++)
                {
                    if(Board[j+1][i]==0 && Board[j][i]!=0)
                    {
                        Board[j+1][i]=Board[j][i];
                        Board[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<3;j++)
                {
                    if(Board[j+1][i]==0 && Board[j][i]!=0)
                    {
                        Board[j+1][i]=Board[j][i];
                        Board[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=3;j>0;j--)
                {
                    if(Board[j-1][i]==Board[j][i] && Board[j][i]!=0)
                    {
                        score+=Board[j-1][i];
                        Board[j][i] *= 2;
                        Board[j-1][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<3;j++)
                {
                    if(Board[j+1][i]==0 && Board[j][i]!=0)
                    {
                        Board[j+1][i]=Board[j][i];
                        Board[j][i]=0;
                    }
                }
                for(int j=0;j<3;j++)
                {
                    if(Board[j+1][i]==0 && Board[j][i]!=0)
                    {
                        Board[j+1][i]=Board[j][i];
                        Board[j][i]=0;
                    }
                }
            }
            if(movement)
            {
                if(cstack.size()<5)
                cstack.push_back(config);
                else if(cstack.size()>=5)
                {
                    cstack.pop_front();
                    cstack.push_back(config);
                }
            }
            setscore(score);
            stat=checkBoard();
            randomizer(stat,movement);
            setpics();
            checkwin();
             qDebug()<< "stat = " << stat << " mov = "<< movement << " ff = "<< ff<<endl;
            thegame::stat=thegame::checkBoard();
            if(stat){
                if(thegame::completeboard())
                {
                    scorefile();
                    saveHighscores();
                    cstack.clear();
                    savegame();
                    hide();
                    gover=new Gameover(this);
                    gover->show();

                }
            }
        }
}

void thegame::setpics(){
    if(Board[0][0]==2)
    {
      QString s="2";
      ui->label_1->setText(s);
      ui->label_1->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][1]==2)
    {
      QString s="2";
      ui->label_2->setText(s);
      ui->label_2->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][2]==2)
    {
      QString s="2";
      ui->label_3->setText(s);
      ui->label_3->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][3]==2)
    {
      QString s="2";
      ui->label_4->setText(s);
      ui->label_4->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][0]==2)
    {
      QString s="2";
      ui->label_5->setText(s);
      ui->label_5->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][1]==2)
    {
      QString s="2";
      ui->label_6->setText(s);
      ui->label_6->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][2]==2)
    {
      QString s="2";
      ui->label_7->setText(s);
      ui->label_7->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][3]==2)
    {
      QString s="2";
      ui->label_8->setText(s);
      ui->label_8->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][0]==2)
    {
      QString s="2";
      ui->label_9->setText(s);
      ui->label_9->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][1]==2)
    {
      QString s="2";
      ui->label_10->setText(s);
      ui->label_10->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][2]==2)
    {
      QString s="2";
      ui->label_11->setText(s);
      ui->label_11->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][3]==2)
    {
      QString s="2";
      ui->label_12->setText(s);
      ui->label_12->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][0]==2)
    {
      QString s="2";
      ui->label_13->setText(s);
      ui->label_13->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][1]==2)
    {
      QString s="2";
      ui->label_14->setText(s);
      ui->label_14->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][2]==2)
    {
      QString s="2";
      ui->label_15->setText(s);
      ui->label_15->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][3]==2)
    {
      QString s="2";
      ui->label_16->setText(s);
      ui->label_16->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][0]==4)
    {
      QString s="4";
      ui->label_1->setText(s);
      ui->label_1->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][1]==4)
    {
      QString s="4";
      ui->label_2->setText(s);
      ui->label_2->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][2]==4)
    {
      QString s="4";
      ui->label_3->setText(s);
      ui->label_3->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][3]==4)
    {
      QString s="4";
      ui->label_4->setText(s);
      ui->label_4->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][0]==4)
    {
      QString s="4";
      ui->label_5->setText(s);
      ui->label_5->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][1]==4)
    {
      QString s="4";
      ui->label_6->setText(s);
      ui->label_6->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][2]==4)
    {
      QString s="4";
      ui->label_7->setText(s);
      ui->label_7->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][3]==4)
    {
      QString s="4";
      ui->label_8->setText(s);
      ui->label_8->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][0]==4)
    {
      QString s="4";
      ui->label_9->setText(s);
      ui->label_9->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][1]==4)
    {
      QString s="4";
      ui->label_10->setText(s);
      ui->label_10->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][2]==4)
    {
      QString s="4";
      ui->label_11->setText(s);
      ui->label_11->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][3]==4)
    {
      QString s="4";
      ui->label_12->setText(s);
      ui->label_12->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][0]==4)
    {
      QString s="4";
      ui->label_13->setText(s);
      ui->label_13->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][1]==4)
    {
      QString s="4";
      ui->label_14->setText(s);
      ui->label_14->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][2]==4)
    {
      QString s="4";
      ui->label_15->setText(s);
      ui->label_15->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][3]==4)
    {
      QString s="4";
      ui->label_16->setText(s);
      ui->label_16->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][0]==8)
    {
      QString s="8";
      ui->label_1->setText(s);
      ui->label_1->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][1]==8)
    {
      QString s="8";
      ui->label_2->setText(s);
      ui->label_2->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][2]==8)
    {
      QString s="8";
      ui->label_3->setText(s);
      ui->label_3->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][3]==8)
    {
      QString s="8";
      ui->label_4->setText(s);
      ui->label_4->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][0]==8)
    {
      QString s="8";
      ui->label_5->setText(s);
      ui->label_5->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][1]==8)
    {
      QString s="8";
      ui->label_6->setText(s);
      ui->label_6->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][2]==8)
    {
      QString s="8";
      ui->label_7->setText(s);
      ui->label_7->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][3]==8)
    {
      QString s="8";
      ui->label_8->setText(s);
      ui->label_8->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][0]==8)
    {
      QString s="8";
      ui->label_9->setText(s);
      ui->label_9->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][1]==8)
    {
      QString s="8";
      ui->label_10->setText(s);
      ui->label_10->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][2]==8)
    {
      QString s="8";
      ui->label_11->setText(s);
      ui->label_11->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][3]==8)
    {
      QString s="8";
      ui->label_12->setText(s);
      ui->label_12->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][0]==8)
    {
      QString s="8";
      ui->label_13->setText(s);
      ui->label_13->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][1]==8)
    {
      QString s="8";
      ui->label_14->setText(s);
      ui->label_14->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][2]==8)
    {
      QString s="8";
      ui->label_15->setText(s);
      ui->label_15->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][3]==8)
    {
      QString s="8";
      ui->label_16->setText(s);
      ui->label_16->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][0]==16)
    {
      QString s="16";
      ui->label_1->setText(s);
      ui->label_1->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][1]==16)
    {
      QString s="16";
      ui->label_2->setText(s);
      ui->label_2->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][2]==16)
    {
      QString s="16";
      ui->label_3->setText(s);
      ui->label_3->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][3]==16)
    {
      QString s="16";
      ui->label_4->setText(s);
      ui->label_4->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][0]==16)
    {
      QString s="16";
      ui->label_5->setText(s);
      ui->label_5->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][1]==16)
    {
      QString s="16";
      ui->label_6->setText(s);
      ui->label_6->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][2]==16)
    {
      QString s="16";
      ui->label_7->setText(s);
      ui->label_7->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][3]==16)
    {
      QString s="16";
      ui->label_8->setText(s);
      ui->label_8->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][0]==16)
    {
      QString s="16";
      ui->label_9->setText(s);
      ui->label_9->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][1]==16)
    {
      QString s="16";
      ui->label_10->setText(s);
      ui->label_10->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][2]==16)
    {
      QString s="16";
      ui->label_11->setText(s);
      ui->label_11->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][3]==16)
    {
      QString s="16";
      ui->label_12->setText(s);
      ui->label_12->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][0]==16)
    {
      QString s="16";
      ui->label_13->setText(s);
      ui->label_13->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][1]==16)
    {
      QString s="16";
      ui->label_14->setText(s);
      ui->label_14->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][2]==16)
    {
      QString s="16";
      ui->label_15->setText(s);
      ui->label_15->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][3]==16)
    {
      QString s="16";
      ui->label_16->setText(s);
      ui->label_16->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][0]==32)
    {
      QString s="32";
      ui->label_1->setText(s);
      ui->label_1->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][1]==32)
    {
      QString s="32";
      ui->label_2->setText(s);
      ui->label_2->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][2]==32)
    {
      QString s="32";
      ui->label_3->setText(s);
      ui->label_3->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][3]==32)
    {
      QString s="32";
      ui->label_4->setText(s);
      ui->label_4->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][0]==32)
    {
      QString s="32";
      ui->label_5->setText(s);
      ui->label_5->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][1]==32)
    {
      QString s="32";
      ui->label_6->setText(s);
      ui->label_6->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][2]==32)
    {
      QString s="32";
      ui->label_7->setText(s);
      ui->label_7->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][3]==32)
    {
      QString s="32";
      ui->label_8->setText(s);
      ui->label_8->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][0]==32)
    {
      QString s="32";
      ui->label_9->setText(s);
      ui->label_9->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][1]==32)
    {
      QString s="32";
      ui->label_10->setText(s);
      ui->label_10->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][2]==32)
    {
      QString s="32";
      ui->label_11->setText(s);
      ui->label_11->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][3]==32)
    {
      QString s="32";
      ui->label_12->setText(s);
      ui->label_12->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][0]==32)
    {
      QString s="32";
      ui->label_13->setText(s);
      ui->label_13->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][1]==32)
    {
      QString s="32";
      ui->label_14->setText(s);
      ui->label_14->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][2]==32)
    {
      QString s="32";
      ui->label_15->setText(s);
      ui->label_15->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][3]==32)
    {
      QString s="32";
      ui->label_16->setText(s);
      ui->label_16->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][0]==64)
    {
      QString s="64";
      ui->label_1->setText(s);
      ui->label_1->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][1]==64)
    {
      QString s="64";
      ui->label_2->setText(s);
      ui->label_2->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][2]==64)
    {
      QString s="64";
      ui->label_3->setText(s);
      ui->label_3->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][3]==64)
    {
      QString s="64";
      ui->label_4->setText(s);
      ui->label_4->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][0]==64)
    {
      QString s="64";
      ui->label_5->setText(s);
      ui->label_5->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][1]==64)
    {
      QString s="64";
      ui->label_6->setText(s);
      ui->label_6->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][2]==64)
    {
      QString s="64";
      ui->label_7->setText(s);
      ui->label_7->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][3]==64)
    {
      QString s="64";
      ui->label_8->setText(s);
      ui->label_8->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][0]==64)
    {
      QString s="64";
      ui->label_9->setText(s);
      ui->label_9->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][1]==64)
    {
      QString s="64";
      ui->label_10->setText(s);
      ui->label_10->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][2]==64)
    {
      QString s="64";
      ui->label_11->setText(s);
      ui->label_11->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][3]==64)
    {
      QString s="64";
      ui->label_12->setText(s);
      ui->label_12->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][0]==64)
    {
      QString s="64";
      ui->label_13->setText(s);
      ui->label_13->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][1]==64)
    {
      QString s="64";
      ui->label_14->setText(s);
      ui->label_14->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][2]==64)
    {
      QString s="64";
      ui->label_15->setText(s);
      ui->label_15->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][3]==64)
    {
      QString s="64";
      ui->label_16->setText(s);
      ui->label_16->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][0]==128)
    {
      QString s="128";
      ui->label_1->setText(s);
      ui->label_1->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][1]==128)
    {
      QString s="128";
      ui->label_2->setText(s);
      ui->label_2->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][2]==128)
    {
      QString s="128";
      ui->label_3->setText(s);
      ui->label_3->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][3]==128)
    {
      QString s="128";
      ui->label_4->setText(s);
      ui->label_4->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][0]==128)
    {
      QString s="128";
      ui->label_5->setText(s);
      ui->label_5->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][1]==128)
    {
      QString s="128";
      ui->label_6->setText(s);
      ui->label_6->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][2]==128)
    {
      QString s="128";
      ui->label_7->setText(s);
      ui->label_7->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][3]==128)
    {
      QString s="128";
      ui->label_8->setText(s);
      ui->label_8->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][0]==128)
    {
      QString s="128";
      ui->label_9->setText(s);
      ui->label_9->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][1]==128)
    {
      QString s="128";
      ui->label_10->setText(s);
      ui->label_10->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][2]==128)
    {
      QString s="128";
      ui->label_11->setText(s);
      ui->label_11->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][3]==128)
    {
      QString s="128";
      ui->label_12->setText(s);
      ui->label_12->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][0]==128)
    {
      QString s="128";
      ui->label_13->setText(s);
      ui->label_13->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][1]==128)
    {
      QString s="128";
      ui->label_14->setText(s);
      ui->label_14->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][2]==128)
    {
      QString s="128";
      ui->label_15->setText(s);
      ui->label_15->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][3]==128)
    {
      QString s="128";
      ui->label_16->setText(s);
      ui->label_16->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][0]==0)
    {
      QString s="";
      ui->label_1->setText(s);
      ui->label_1->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(Board[0][1]==0)
    {
      QString s="";
      ui->label_2->setText(s);
      ui->label_2->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(Board[0][2]==0)
    {
      QString s="";
      ui->label_3->setText(s);
      ui->label_3->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(Board[0][3]==0)
    {
      QString s="";
      ui->label_4->setText(s);
      ui->label_4->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(Board[1][0]==0)
    {
      QString s="";
      ui->label_5->setText(s);
      ui->label_5->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(Board[1][1]==0)
    {
      QString s="";
      ui->label_6->setText(s);
      ui->label_6->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(Board[1][2]==0)
    {
      QString s="";
      ui->label_7->setText(s);
      ui->label_7->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(Board[1][3]==0)
    {
      QString s="";
      ui->label_8->setText(s);
      ui->label_8->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(Board[2][0]==0)
    {
      QString s="";
      ui->label_9->setText(s);
      ui->label_9->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(Board[2][1]==0)
    {
      QString s="";
      ui->label_10->setText(s);
      ui->label_10->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(Board[2][2]==0)
    {
      QString s="";
      ui->label_11->setText(s);
      ui->label_11->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(Board[2][3]==0)
    {
      QString s="";
      ui->label_12->setText(s);
      ui->label_12->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(Board[3][0]==0)
    {
      QString s="";
      ui->label_13->setText(s);
      ui->label_13->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(Board[3][1]==0)
    {
      QString s="";
      ui->label_14->setText(s);
      ui->label_14->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(Board[3][2]==0)
    {
      QString s="";
      ui->label_15->setText(s);
      ui->label_15->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(Board[3][3]==0)
    {
      QString s="";
      ui->label_16->setText(s);
      ui->label_16->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(Board[0][0]==256)
    {
      QString s= QString::number(256);
      ui->label_1->setText(s);
      ui->label_1->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][1]==256)
    {
      QString s= QString::number(256);
      ui->label_2->setText(s);
      ui->label_2->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][2]==256)
    {
      QString s= QString::number(256);
      ui->label_3->setText(s);
      ui->label_3->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][3]==256)
    {
      QString s= QString::number(256);
      ui->label_4->setText(s);
      ui->label_4->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][0]==256)
    {
      QString s= QString::number(256);
      ui->label_5->setText(s);
      ui->label_5->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][1]==256)
    {
      QString s= QString::number(256);
      ui->label_6->setText(s);
      ui->label_6->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][2]==256)
    {
      QString s= QString::number(256);
      ui->label_7->setText(s);
      ui->label_7->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][3]==256)
    {
      QString s= QString::number(256);
      ui->label_8->setText(s);
      ui->label_8->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][0]==256)
    {
      QString s= QString::number(256);
      ui->label_9->setText(s);
      ui->label_9->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][1]==256)
    {
      QString s= QString::number(256);
      ui->label_10->setText(s);
      ui->label_10->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][2]==256)
    {
      QString s= QString::number(256);
      ui->label_11->setText(s);
      ui->label_11->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][3]==256)
    {
      QString s= QString::number(256);
      ui->label_12->setText(s);
      ui->label_12->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][0]==256)
    {
      QString s= QString::number(256);
      ui->label_13->setText(s);
      ui->label_13->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][1]==256)
    {
      QString s= QString::number(256);
      ui->label_14->setText(s);
      ui->label_14->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][2]==256)
    {
      QString s= QString::number(256);
      ui->label_15->setText(s);
      ui->label_15->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][3]==256)
    {
      QString s= QString::number(256);
      ui->label_16->setText(s);
      ui->label_16->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][0]==512)
    {
      QString s= QString::number(512);
      ui->label_1->setText(s);
      ui->label_1->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][1]==512)
    {
      QString s= QString::number(512);
      ui->label_2->setText(s);
      ui->label_2->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][2]==512)
    {
      QString s= QString::number(512);
      ui->label_3->setText(s);
      ui->label_3->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][3]==512)
    {
      QString s= QString::number(512);
      ui->label_4->setText(s);
      ui->label_4->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][0]==512)
    {
      QString s= QString::number(512);
      ui->label_5->setText(s);
      ui->label_5->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][1]==512)
    {
      QString s= QString::number(512);
      ui->label_6->setText(s);
      ui->label_6->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][2]==512)
    {
      QString s= QString::number(512);
      ui->label_7->setText(s);
      ui->label_7->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][3]==512)
    {
      QString s= QString::number(512);
      ui->label_8->setText(s);
      ui->label_8->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][0]==512)
    {
      QString s= QString::number(512);
      ui->label_9->setText(s);
      ui->label_9->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][1]==512)
    {
      QString s= QString::number(512);
      ui->label_10->setText(s);
      ui->label_10->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][2]==512)
    {
      QString s= QString::number(512);
      ui->label_11->setText(s);
      ui->label_11->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][3]==512)
    {
      QString s= QString::number(512);
      ui->label_12->setText(s);
      ui->label_12->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][0]==512)
    {
      QString s= QString::number(512);
      ui->label_13->setText(s);
      ui->label_13->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][1]==512)
    {
      QString s= QString::number(512);
      ui->label_14->setText(s);
      ui->label_14->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][2]==512)
    {
      QString s= QString::number(512);
      ui->label_15->setText(s);
      ui->label_15->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][3]==512)
    {
      QString s= QString::number(512);
      ui->label_16->setText(s);
      ui->label_16->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][0]==1024)
    {
      QString s= QString::number(1024);
      ui->label_1->setText(s);
      ui->label_1->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][1]==1024)
    {
      QString s= QString::number(1024);
      ui->label_2->setText(s);
      ui->label_2->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][2]==1024)
    {
      QString s= QString::number(1024);
      ui->label_3->setText(s);
      ui->label_3->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][3]==1024)
    {
      QString s= QString::number(1024);
      ui->label_4->setText(s);
      ui->label_4->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][0]==1024)
    {
      QString s= QString::number(1024);
      ui->label_5->setText(s);
      ui->label_5->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][1]==1024)
    {
      QString s= QString::number(1024);
      ui->label_6->setText(s);
      ui->label_6->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][2]==1024)
    {
      QString s= QString::number(1024);
      ui->label_7->setText(s);
      ui->label_7->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][3]==1024)
    {
      QString s= QString::number(1024);
      ui->label_8->setText(s);
      ui->label_8->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][0]==1024)
    {
      QString s= QString::number(1024);
      ui->label_9->setText(s);
      ui->label_9->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][1]==1024)
    {
      QString s= QString::number(1024);
      ui->label_10->setText(s);
      ui->label_10->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][2]==1024)
    {
      QString s= QString::number(1024);
      ui->label_11->setText(s);
      ui->label_11->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][3]==1024)
    {
      QString s= QString::number(1024);
      ui->label_12->setText(s);
      ui->label_12->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][0]==1024)
    {
      QString s= QString::number(1024);
      ui->label_13->setText(s);
      ui->label_13->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][1]==1024)
    {
      QString s= QString::number(1024);
      ui->label_14->setText(s);
      ui->label_14->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][2]==1024)
    {
      QString s= QString::number(1024);
      ui->label_15->setText(s);
      ui->label_15->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][3]==1024)
    {
      QString s= QString::number(1024);
      ui->label_16->setText(s);
      ui->label_16->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][0]==2048)
    {
      QString s= QString::number(2048);
      ui->label_1->setText(s);
      ui->label_1->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][1]==2048)
    {
      QString s= QString::number(2048);
      ui->label_2->setText(s);
      ui->label_2->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][2]==2048)
    {
      QString s= QString::number(2048);
      ui->label_3->setText(s);
      ui->label_3->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[0][3]==2048)
    {
      QString s= QString::number(2048);
      ui->label_4->setText(s);
      ui->label_4->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][0]==2048)
    {
      QString s= QString::number(2048);
      ui->label_5->setText(s);
      ui->label_5->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][1]==2048)
    {
      QString s= QString::number(2048);
      ui->label_6->setText(s);
      ui->label_6->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][2]==2048)
    {
      QString s= QString::number(2048);
      ui->label_7->setText(s);
      ui->label_7->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[1][3]==2048)
    {
      QString s= QString::number(2048);
      ui->label_8->setText(s);
      ui->label_8->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][0]==2048)
    {
      QString s= QString::number(2048);
      ui->label_9->setText(s);
      ui->label_9->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][1]==2048)
    {
      QString s= QString::number(2048);
      ui->label_10->setText(s);
      ui->label_10->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][2]==2048)
    {
      QString s= QString::number(2048);
      ui->label_11->setText(s);
      ui->label_11->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[2][3]==2048)
    {
      QString s= QString::number(2048);
      ui->label_12->setText(s);
      ui->label_12->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][0]==2048)
    {
      QString s= QString::number(2048);
      ui->label_13->setText(s);
      ui->label_13->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][1]==2048)
    {
      QString s= QString::number(2048);
      ui->label_14->setText(s);
      ui->label_14->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][2]==2048)
    {
      QString s= QString::number(2048);
      ui->label_15->setText(s);
      ui->label_15->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    }
    if(Board[3][3]==2048)
    {
      QString s= QString::number(2048);
      ui->label_16->setText(s);
      ui->label_16->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    }
   int k=Board[0][0];
    QString s= QString::number(k);
    if(k>0)
    ui->label_1->setText(s);
    if(k>2048)
      ui->label_1->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board[0][1];
     s= QString::number(k);
    if(k>0)
    ui->label_2->setText(s);
    if(k>2048)
      ui->label_2->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board[0][2];
     s= QString::number(k);
    if(k>0)
    ui->label_3->setText(s);
    if(k>2048)
      ui->label_3->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board[0][3];
     s= QString::number(k);
    if(k>0)
    ui->label_4->setText(s);
    if(k>2048)
      ui->label_4->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board[1][0];
     s= QString::number(k);
    if(k>0)
    ui->label_5->setText(s);
    if(k>2048)
      ui->label_5->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board[1][1];
     s= QString::number(k);
    if(k>0)
    ui->label_6->setText(s);
    if(k>2048)
      ui->label_6->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board[1][2];
     s= QString::number(k);
    if(k>0)
    ui->label_7->setText(s);
    if(k>2048)
      ui->label_7->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board[1][3];
     s= QString::number(k);
    if(k>0)
    ui->label_8->setText(s);
    if(k>2048)
      ui->label_8->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board[2][0];
     s= QString::number(k);
    if(k>0)
    ui->label_9->setText(s);
    if(k>2048)
      ui->label_9->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board[2][1];
     s= QString::number(k);
    if(k>0)
    ui->label_10->setText(s);
    if(k>2048)
      ui->label_10->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board[2][2];
     s= QString::number(k);
    if(k>0)
    ui->label_11->setText(s);
    if(k>2048)
      ui->label_11->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board[2][3];
     s= QString::number(k);
    if(k>0)
    ui->label_12->setText(s);
    if(k>2048)
      ui->label_12->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board[3][0];
     s= QString::number(k);
    if(k>0)
    ui->label_13->setText(s);
    if(k>2048)
      ui->label_13->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board[3][1];
     s= QString::number(k);
    if(k>0)
    ui->label_14->setText(s);
    if(k>2048)
      ui->label_14->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board[3][2];
     s= QString::number(k);
    if(k>0)
    ui->label_15->setText(s);
    if(k>2048)
      ui->label_15->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board[3][3];
     s= QString::number(k);
    if(k>0)
    ui->label_16->setText(s);
    if(k>2048)
      ui->label_16->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");
}

void thegame::savegame(){

    QString siddu="/home/siddu/Downloads/gamepro/contents.txt";
    QString sunny="/home/yashwanth/Projects/gamepro/contents.txt";
    QFile savefile("contents.txt");
    if (!savefile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "failed to save";
           return;
    }
    QTextStream out(&savefile);
    out << cstack.size()<<"\n";

   for(int c=0;c<cstack.size();c++){
       out << "4\n";
    for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                out << cstack[c].B[i][j] << "\n";
            }
        }
        out << cstack[c].score <<"\n";
        out << "0\n" ;
        if(cstack[c].movement==false)
        out << "0\n";
        else
            out << "1\n";
        if(cstack[c].stat==false)
        out << "0\n";
        else
            out << "1\n";
        if(cstack[c].ff==false)
            out<<"0\n";
        else
            out<<"1\n";
   }
}
void thegame::loadgame(){

    QString siddu="/home/siddu/Downloads/gamepro/contents.txt";
    QString sunny="/home/yashwanth/Projects/gamepro/contents.txt";

    QFile file("contents.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
          qDebug() << "failed in loading the game ";
           return;
        }
       qDebug()<<" Game loaded "<<endl;
       cstack.clear();
       QTextStream in(&file);
       QString line = in.readLine();
      // QTextStream in(&file);
       int size=line.toInt();
       for(int c=0;c<size;c++){
           Config temp;

             line = in.readLine(); // 4 5 6

       for(int i=0;i<4;i++)
           {
               for(int j=0;j<4;j++)
               {
                     QString line = in.readLine();
                    int k=line.toInt();
                    temp.B[i][j]=k;
               }
           }

        line = in.readLine(); // score
        int k=line.toInt();
        temp.score=k;
        line =in.readLine(); // highscore
        //setscore(k);
        //setpics();
        line = in.readLine(); // movement
        k= line.toInt();
        if(k==1)
        temp.movement=true;
        else
            temp.movement=false;
        line = in.readLine(); // stat
        k= line.toInt();
        if(k==1)
        temp.stat=true;
        else
            temp.stat=false;
        line = in.readLine(); // stat
        k= line.toInt();
        if(k==1){
        ff11=true;
        temp.ff=true;
        }
        else
        {
            ff11=false;
            temp.ff=false;
        }
        cstack.push_back(temp);
      }
       Config temp1=cstack.top();
       int a=cstack.size()-1;
       QString ss=QString::number(a);
       ui->undobutton->setText(ss);
       cstack.pop();
       for(int i=0;i<4;i++)
           {
               for(int j=0;j<4;j++)
               {
                    Board[i][j]=temp1.B[i][j];
               }
           }
       stat=temp1.stat;
       movement=temp1.movement;
       score=temp1.score;
       stat=checkBoard();
       setscore(score);
       setpics();
       checkwin();

}
void thegame::undogame(){
    if(!cstack.empty())
    {
        Config temp=cstack.top();
        cstack.pop_back();
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                Board[i][j]=temp.B[i][j];
        stat=temp.stat;
        movement=temp.movement;
        score=temp.score;
        setpics();
        setscore(score);
        int k=cstack.size();
        QString ss=QString::number(k);
      //  QString s="Undo";
       // s=s+ss;
      //  ui->undobutton->setText(ss);
        checkwin();
    }
}
void thegame::scorefile(){

    QString siddu="/home/siddu/Downloads/gamepro/score.txt";
    QString sunny="/home/yashwanth/Projects/gamepro/score.txt";
    QFile file("score.txt");
    if (!file.open(QIODevice::WriteOnly))
    {
       qDebug() << "failed in thegame::scorefile";
        return;
     }
    QTextStream out(&file);
    out << score <<"\n";
}
void thegame::saveHighscores(){

    QString siddu="/home/siddu/Downloads/gamepro/leaderboard.txt";
    QString sunny="/home/yashwanth/Projects/gamepro/leaderboard.txt";
    QFile file("leaderboard.txt");
       if (!file.open(QIODevice::WriteOnly))
       {
          qDebug() << "failed in savehighscores ";
           return;
        }
      Best[0]=highscore;
    QTextStream out(&file);
    out << Best[0] <<"\n";
    out << Best[1] <<"\n";
     out << Best[2] <<"\n";
}
void thegame::seeHighscore(){
    QString siddu="/home/siddu/Downloads/gamepro/leaderboard.txt";
    QString sunny="/home/yashwanth/Projects/gamepro/leaderboard.txt";
    QFile file("leaderboard.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
          qDebug() << "failed in seeHighscores ";
           return;
        }
       else
           qDebug() << " opened";
       QTextStream in(&file);
     QString line = in.readLine();
    highscore=line.toInt();
    ui->highscorelabel->setText(line);
    Best[0]=line.toInt();
    line=in.readLine();
    Best[1]=line.toInt();
    line=in.readLine();
     Best[2]=line.toInt();

}
thegame::thegame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::thegame)
{
    ui->setupUi(this);
    QString siddu="/home/siddu/Downloads/gamepro/images/2048_logo.svg";
    QString sunny=":/resources/images/2048_logo.svg";
    QPixmap pic(sunny);
    int w=ui->label_20->width();
    int h=ui->label_20->height();
    ui->label_20->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));
    //ui->label->resize(100,100);
    bool movement=true;
    thegame::Newgame();
    bool stat=false;
    thegame::randomizer(stat,movement);
    setscore(score);
    seeHighscore();
    thegame::setpics();
    qDebug()<< "stat = " << stat << " mov = "<< movement << " ff = "<< ff<<endl;
    //saveHighscores();

}

thegame::~thegame()
{
    delete ui;
}
void thegame::keyPressEvent(QKeyEvent *event){
        thegame::update(event);
}

void thegame::on_pushButton_3_clicked()
{
    pop.play();
    Newgame();
    stat=checkBoard();
    randomizer(stat,true);
    setpics();
    score=0;

    setscore(score);
    cstack.clear();
}

void thegame::on_optionstab_clicked()
{
    pop.play();
    setConfig(Board,stat,movement,score,0,ff);
    cstack.push_back(config);
        savegame();
        QApplication::exit();
}



void thegame::on_undobutton_clicked()
{
    pop.play();
    undogame();
    qDebug() << cstack.size() <<"\n";
}
