#include "thegame5x5.h"
#include "ui_thegame5x5.h"
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

int cc=0;
int ff1=false;
class Config1{
public:
    int B[5][5];
    bool stat;
    bool movement;
    int score;
    int highscore;
    bool ff;
};
Config1 config1;
QStack< Config1 > cstack1;
void setConfig1(int Board1[][5],bool Stat,bool Movement,int Score,int Highscore,bool ff)
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            config1.B[i][j]=Board1[i][j];
    config1.stat=Stat;
    config1.movement=Movement;
    config1.score=Score;
    config1.highscore=Highscore;
    config1.ff=ff;
}
void thegame5x5::setscore(int score){
    std::stringstream s;
    s << score ;
    std::string a=s.str();
    QString ss =QString::fromStdString(a);
    ui->label_28->setText(ss);

    if(score>highscore){
        ui->highscorelabel->setText(ss);
        highscore=score;
    }
    QString sk="Undo";
            //sk=sk+QString::number(cstack.size());

    ui->undobutton->setText(sk);
    ui->undobutton->setStyleSheet("background: rgb( 245, 176, 65 );color: rgb(119,110,101); font: bold;font: 15pt;border-color: rgb(220, 118, 51);border-width:2.5px;border-style:outset;");
    if(cstack1.size()==0)
    {
        ui->undobutton->setStyleSheet("background: rgb( 245, 176, 65 );color: rgb(119,110,101); font: bold;font: 15pt;");
    }

}
void thegame5x5::randomizer(bool status,bool m){
    if(!m)
        return;
    if(status==false)
    {
        int i,j;
        i=rand()%5;
        j=rand()%5;
        while(Board1[i][j]!=0)
        {
            i=rand()%5;
            j=rand()%5;

        }
        if(cc!=10)
        {Board1[i][j]=2;
            cc++;
        }
        else
        {
            Board1[i][j]=4;
            cc=0;
        }
        movement=false;
    }
}
bool thegame5x5::checkBoard(){
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(Board1[i][j]==0)
                return false;
        }
    }
    return true;
}
void thegame5x5::checkwin(){
    qDebug()<<" ff "<<ff<<endl;
    if(ff1==true)
        return;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(Board1[i][j]==2048)
            {
                //hide();
                qDebug()<< "win "<<ff1<<endl;
                gwin=new gamewin(this);

                gwin->show();
                ff=true;
                ff1=true;
                return ;
            }
        }
    }
}

bool thegame5x5::completeboard(){

    for(int i=0;i<4;i++)
    {
        for(int j=1;j<5;j++)
        {
            if(Board1[i][j-1]==Board1[i][j])
                return false;
            if(Board1[i][j]==Board1[i+1][j])
                return false;
        }
    }
    for(int i=0;i<4;i++)
    {
        if(Board1[i][0]==Board1[i+1][0])
        return false;
        if(Board1[4][i]==Board1[4][i+1])
        return false;
    }
    return true;

}
void thegame5x5::Newgame(){
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            Board1[i][j]=0;
        }
    }
    score=0;
}
void thegame5x5::update(QKeyEvent* event1)
{
        if(event1->key()==Qt::Key_A)
        {
            setConfig1(Board1,stat,movement,score,0,ff);


            for(int i=0;i<5;i++)
            {
                for(int j=4;j>0;j--)
                {
                    if(Board1[i][j-1]==0 && Board1[i][j]!=0)
                    {
                        Board1[i][j-1]=Board1[i][j];
                        Board1[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=4;j>0;j--)
                {
                    if(Board1[i][j-1]==0 && Board1[i][j]!=0)
                    {
                        Board1[i][j-1]=Board1[i][j];
                        Board1[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=4;j>0;j--)
                {
                    if(Board1[i][j-1]==0 && Board1[i][j]!=0)
                    {
                        Board1[i][j-1]=Board1[i][j];
                        Board1[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=4;j>0;j--)
                {
                    if(Board1[i][j-1]==0 && Board1[i][j]!=0)
                    {
                        Board1[i][j-1]=Board1[i][j];
                        Board1[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<4;j++)
                {
                    if(Board1[i][j+1]==Board1[i][j] && Board1[i][j]!=0)
                    {
                        score+= Board1[i][j];
                        Board1[i][j] *= 2;
                        Board1[i][j+1]=0;
                        movement=true;

                    }
                }
                for(int j=4;j>0;j--)
                {
                    if(Board1[i][j-1]==0 && Board1[i][j]!=0)
                    {
                        Board1[i][j-1]=Board1[i][j];
                        Board1[i][j]=0;
                    }
                }
                for(int j=4;j>0;j--)
                {
                    if(Board1[i][j-1]==0 && Board1[i][j]!=0)
                    {
                        Board1[i][j-1]=Board1[i][j];
                        Board1[i][j]=0;
                    }
                }
                for(int j=4;j>0;j--)
                {
                    if(Board1[i][j-1]==0 && Board1[i][j]!=0)
                    {
                        Board1[i][j-1]=Board1[i][j];
                        Board1[i][j]=0;
                    }
                }
            }
            if(movement)
            {
                if(cstack1.size()<5)
                cstack1.push_back(config1);
                else if(cstack1.size()>=5)
                {
                    cstack1.pop_front();
                    cstack1.push_back(config1);
                }
            }
            setscore(score);
            stat=checkBoard();
            randomizer(stat,movement);
            setpics();
            checkwin();
            thegame5x5::stat=thegame5x5::checkBoard();
            if(stat){
                if(thegame5x5::completeboard())
                {
                    scorefile();
                    saveHighscores();
                    hide();
                    gover=new Gameover(this);
                    gover->show();

                }
            }
        }
        if(event1->key()==Qt::Key_D)
        {
            setConfig1(Board1,stat,movement,score,0,ff);


            for(int i=0;i<5;i++)
            {
                for(int j=0;j<4;j++)
                {
                    if(Board1[i][j+1]==0 && Board1[i][j]!=0)
                    {
                        Board1[i][j+1]=Board1[i][j];
                        Board1[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<4;j++)
                {
                    if(Board1[i][j+1]==0 && Board1[i][j]!=0)
                    {
                        Board1[i][j+1]=Board1[i][j];
                        Board1[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<4;j++)
                {
                    if(Board1[i][j+1]==0 && Board1[i][j]!=0)
                    {
                        Board1[i][j+1]=Board1[i][j];
                        Board1[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<4;j++)
                {
                    if(Board1[i][j+1]==0 && Board1[i][j]!=0)
                    {
                        Board1[i][j+1]=Board1[i][j];
                        Board1[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=4;j>0;j--)
                {
                    if(Board1[i][j-1]==Board1[i][j] && Board1[i][j]!=0)
                    {
                        score+=Board1[i][j-1];
                        Board1[i][j] *= 2;
                        Board1[i][j-1]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<4;j++)
                {
                    if(Board1[i][j+1]==0 && Board1[i][j]!=0)
                    {
                        Board1[i][j+1]=Board1[i][j];
                        Board1[i][j]=0;
                    }
                }
                for(int j=0;j<4;j++)
                {
                    if(Board1[i][j+1]==0 && Board1[i][j]!=0)
                    {
                        Board1[i][j+1]=Board1[i][j];
                        Board1[i][j]=0;
                    }
                }
                for(int j=0;j<4;j++)
                {
                    if(Board1[i][j+1]==0 && Board1[i][j]!=0)
                    {
                        Board1[i][j+1]=Board1[i][j];
                        Board1[i][j]=0;
                    }
                }
            }
            if(movement)
            {
                if(cstack1.size()<5)
                cstack1.push_back(config1);
                else if(cstack1.size()>=5)
                {
                    cstack1.pop_front();
                    cstack1.push_back(config1);
                }
            }
            setscore(score);
            stat=checkBoard();
            randomizer(stat,movement);
            setpics();
            checkwin();
            thegame5x5::stat=thegame5x5::checkBoard();
            if(stat){
                if(thegame5x5::completeboard())
                {
                    scorefile();
                    saveHighscores();
                    hide();
                    gover=new Gameover(this);
                    gover->show();

                }
            }
        }
        if(event1->key()==Qt::Key_W)
        {
            setConfig1(Board1,stat,movement,score,0,ff);


            for(int i=0;i<5;i++){
                for(int j=4;j>0;j--)
                {
                    if(Board1[j-1][i]==0 && Board1[j][i]!=0)
                    {
                        Board1[j-1][i]=Board1[j][i];
                        Board1[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=4;j>0;j--)
                {
                    if(Board1[j-1][i]==0 && Board1[j][i]!=0)
                    {
                        Board1[j-1][i]=Board1[j][i];
                        Board1[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=4;j>0;j--)
                {
                    if(Board1[j-1][i]==0 && Board1[j][i]!=0)
                    {
                        Board1[j-1][i]=Board1[j][i];
                        Board1[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=4;j>0;j--)
                {
                    if(Board1[j-1][i]==0 && Board1[j][i]!=0)
                    {
                        Board1[j-1][i]=Board1[j][i];
                        Board1[j][i]=0;
                        movement=true;
                    }
                }

                for(int j=0;j<4;j++)
                {
                    if(Board1[j+1][i]==Board1[j][i] && Board1[j][i]!=0)
                    {
                        score+=Board1[j][i];
                        Board1[j][i] *= 2;
                        Board1[j+1][i]=0;
                        movement=true;
                    }
                }
                for(int j=4;j>0;j--)
                {
                    if(Board1[j-1][i]==0 && Board1[j][i]!=0)
                    {
                        Board1[j-1][i]=Board1[j][i];
                        Board1[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=4;j>0;j--)
                {
                    if(Board1[j-1][i]==0 && Board1[j][i]!=0)
                    {
                        Board1[j-1][i]=Board1[j][i];
                        Board1[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=4;j>0;j--)
                {
                    if(Board1[j-1][i]==0 && Board1[j][i]!=0)
                    {
                        Board1[j-1][i]=Board1[j][i];
                        Board1[j][i]=0;
                        movement=true;
                    }
                }

               }
            if(movement){
                if(cstack1.size()<5)
                cstack1.push_back(config1);
                else if(cstack1.size()>=5)
                {
                    cstack1.pop_front();
                    cstack1.push_back(config1);
                }
            }
            setscore(score);
            stat=checkBoard();
            randomizer(stat,movement);
            setpics();
            checkwin();
            thegame5x5::stat=thegame5x5::checkBoard();
            if(stat){
                if(thegame5x5::completeboard())
                {
                    scorefile();
                    saveHighscores();
                    hide();
                    gover=new Gameover(this);
                    gover->show();

                }
            }
        }
        if(event1->key()==Qt::Key_S)
        {
            setConfig1(Board1,stat,movement,score,0,ff);

            for(int i=0;i<5;i++){
                for(int j=0;j<4;j++)
                {
                    if(Board1[j+1][i]==0 && Board1[j][i]!=0)
                    {
                        Board1[j+1][i]=Board1[j][i];
                        Board1[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<4;j++)
                {
                    if(Board1[j+1][i]==0 && Board1[j][i]!=0)
                    {
                        Board1[j+1][i]=Board1[j][i];
                        Board1[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<4;j++)
                {
                    if(Board1[j+1][i]==0 && Board1[j][i]!=0)
                    {
                        Board1[j+1][i]=Board1[j][i];
                        Board1[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<4;j++)
                {
                    if(Board1[j+1][i]==0 && Board1[j][i]!=0)
                    {
                        Board1[j+1][i]=Board1[j][i];
                        Board1[j][i]=0;
                        movement=true;
                    }
                }

                for(int j=4;j>0;j--)
                {
                    if(Board1[j-1][i]==Board1[j][i] && Board1[j][i]!=0)
                    {
                        score+=Board1[j-1][i];
                        Board1[j][i] *= 2;
                        Board1[j-1][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<4;j++)
                {
                    if(Board1[j+1][i]==0 && Board1[j][i]!=0)
                    {
                        Board1[j+1][i]=Board1[j][i];
                        Board1[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<4;j++)
                {
                    if(Board1[j+1][i]==0 && Board1[j][i]!=0)
                    {
                        Board1[j+1][i]=Board1[j][i];
                        Board1[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<4;j++)
                {
                    if(Board1[j+1][i]==0 && Board1[j][i]!=0)
                    {
                        Board1[j+1][i]=Board1[j][i];
                        Board1[j][i]=0;
                        movement=true;
                    }
                }

            }
            if(movement){
                if(cstack1.size()<5)
                cstack1.push_back(config1);
                else if(cstack1.size()>=5)
                {
                    cstack1.pop_front();
                    cstack1.push_back(config1);
                }
            }
            setscore(score);
            stat=checkBoard();
            randomizer(stat,movement);
            setpics();
            checkwin();
            thegame5x5::stat=thegame5x5::checkBoard();
            if(stat){
                if(thegame5x5::completeboard())
                {
                    scorefile();
                    saveHighscores();
                    hide();
                    gover=new Gameover(this);
                    gover->show();

                }
            }
        }
}
void thegame5x5::setpics(){

    int k=Board1[0][0];
    QString s= QString::number(k);
    if(k>0)
    ui->label_1->setText(s);
    if(k==0){
    ui->label_1->setText("");
    ui->label_1->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_1->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_1->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_1->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_1->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_1->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_1->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_1->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_1->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_1->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_1->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_1->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_1->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[0][1];
     s= QString::number(k);
    if(k>0)
    ui->label_2->setText(s);
    if(k==0){
    ui->label_2->setText("");
    ui->label_2->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_2->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_2->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_2->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_2->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_2->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_2->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_2->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_2->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_2->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_2->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_2->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_2->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[0][2];
     s= QString::number(k);
    if(k>0)
    ui->label_3->setText(s);
    if(k==0){
    ui->label_3->setText("");
    ui->label_3->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_3->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_3->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_3->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_3->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_3->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_3->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_3->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_3->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_3->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_3->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_3->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_3->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[0][3];
     s= QString::number(k);
    if(k>0)
    ui->label_4->setText(s);
    if(k==0){
    ui->label_4->setText("");
    ui->label_4->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_4->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_4->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_4->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_4->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_4->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_4->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_4->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_4->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_4->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_4->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_4->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_4->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[0][4];
     s= QString::number(k);
    if(k>0)
    ui->label_5->setText(s);
    if(k==0){
    ui->label_5->setText("");
    ui->label_5->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_5->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_5->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_5->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_5->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_5->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_5->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_5->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_5->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_5->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_5->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_5->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_5->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[1][0];
     s= QString::number(k);
    if(k>0)
    ui->label_6->setText(s);
    if(k==0){
    ui->label_6->setText("");
    ui->label_6->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_6->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_6->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_6->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_6->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_6->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_6->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_6->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_6->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_6->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_6->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_6->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_6->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[1][1];
     s= QString::number(k);
    if(k>0)
    ui->label_7->setText(s);
    if(k==0){
    ui->label_7->setText("");
    ui->label_7->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_7->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_7->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_7->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_7->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_7->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_7->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_7->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_7->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_7->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_7->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_7->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_7->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[1][2];
     s= QString::number(k);
    if(k>0)
    ui->label_8->setText(s);
    if(k==0){
    ui->label_8->setText("");
    ui->label_8->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_8->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_8->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_8->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_8->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_8->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_8->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_8->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_8->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_8->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_8->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_8->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_8->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[1][3];
     s= QString::number(k);
    if(k>0)
    ui->label_9->setText(s);
    if(k==0){
    ui->label_9->setText("");
    ui->label_9->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_9->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_9->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_9->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_9->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_9->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_9->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_9->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_9->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_9->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_9->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_9->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_9->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[1][4];
     s= QString::number(k);
    if(k>0)
    ui->label_10->setText(s);
    if(k==0){
    ui->label_10->setText("");
    ui->label_10->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_10->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_10->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_10->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_10->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_10->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_10->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_10->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_10->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_10->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_10->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_10->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_10->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[2][0];
     s= QString::number(k);
    if(k>0)
    ui->label_11->setText(s);
    if(k==0){
    ui->label_11->setText("");
    ui->label_11->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_11->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_11->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_11->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_11->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_11->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_11->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_11->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_11->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_11->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_11->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_11->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_11->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[2][1];
     s= QString::number(k);
    if(k>0)
    ui->label_12->setText(s);
    if(k==0){
    ui->label_12->setText("");
    ui->label_12->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_12->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_12->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_12->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_12->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_12->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_12->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_12->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_12->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_12->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_12->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_12->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_12->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[2][2];
     s= QString::number(k);
    if(k>0)
    ui->label_13->setText(s);
    if(k==0){
    ui->label_13->setText("");
    ui->label_13->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_13->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_13->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_13->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_13->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_13->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_13->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_13->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_13->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_13->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_13->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_13->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_13->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[2][3];
     s= QString::number(k);
    if(k>0)
    ui->label_14->setText(s);
    if(k==0){
    ui->label_14->setText("");
    ui->label_14->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_14->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_14->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_14->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_14->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_14->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_14->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_14->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_14->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_14->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_14->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_14->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_14->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[2][4];
     s= QString::number(k);
    if(k>0)
    ui->label_15->setText(s);
    if(k==0){
    ui->label_15->setText("");
    ui->label_15->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_15->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_15->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_15->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_15->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_15->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_15->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_15->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_15->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_15->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_15->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_15->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_15->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[3][0];
     s= QString::number(k);
    if(k>0)
    ui->label_16->setText(s);
    if(k==0){
    ui->label_16->setText("");
    ui->label_16->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_16->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_16->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_16->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_16->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_16->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_16->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_16->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_16->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_16->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_16->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_16->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_16->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[3][1];
     s= QString::number(k);
    if(k>0)
    ui->label_17->setText(s);
    if(k==0){
    ui->label_17->setText("");
    ui->label_17->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_17->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_17->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_17->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_17->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_17->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_17->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_17->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_17->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_17->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_17->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_17->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_17->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[3][2];
     s= QString::number(k);
    if(k>0)
    ui->label_18->setText(s);
    if(k==0){
    ui->label_18->setText("");
    ui->label_18->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_18->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_18->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_18->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_18->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_18->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_18->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_18->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_18->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_18->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_18->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_18->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_18->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[3][3];
     s= QString::number(k);
    if(k>0)
    ui->label_19->setText(s);
    if(k==0){
    ui->label_19->setText("");
    ui->label_19->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_19->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_19->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_19->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_19->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_19->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_19->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_19->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_19->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_19->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_19->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_19->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_19->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[3][4];
     s= QString::number(k);
    if(k>0)
    ui->label_20->setText(s);
    if(k==0){
    ui->label_20->setText("");
    ui->label_20->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_20->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_20->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_20->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_20->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_20->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_20->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_20->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_20->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_20->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_20->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_20->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_20->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[4][0];
     s= QString::number(k);
    if(k>0)
    ui->label_21->setText(s);
    if(k==0){
    ui->label_21->setText("");
    ui->label_21->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_21->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_21->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_21->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_21->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_21->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_21->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_21->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_21->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_21->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_21->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_21->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_21->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[4][1];
     s= QString::number(k);
    if(k>0)
    ui->label_22->setText(s);
    if(k==0){
    ui->label_22->setText("");
    ui->label_22->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_22->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_22->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_22->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_22->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_22->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_22->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_22->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_22->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_22->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_22->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_22->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_22->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[4][2];
     s= QString::number(k);
    if(k>0)
    ui->label_23->setText(s);
    if(k==0){
    ui->label_23->setText("");
    ui->label_23->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_23->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_23->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_23->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_23->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_23->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_23->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_23->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_23->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_23->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_23->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_23->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_23->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[4][3];
     s= QString::number(k);
    if(k>0)
    ui->label_24->setText(s);
    if(k==0){
    ui->label_24->setText("");
    ui->label_24->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_24->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_24->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_24->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_24->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_24->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_24->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_24->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_24->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_24->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_24->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_24->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_24->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board1[4][4];
     s= QString::number(k);
    if(k>0)
    ui->label_25->setText(s);
    if(k==0){
    ui->label_25->setText("");
    ui->label_25->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_25->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_25->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_25->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_25->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_25->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_25->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_25->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_25->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_25->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_25->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==2048)
      ui->label_25->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_25->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");

}
void thegame5x5::savegame(){
    QString siddu="/home/siddu/Downloads/gamepro/contents.txt";
    QString sunny="/home/yashwanth/Projects/gamepro/contents.txt";
    QFile savefile("contents.txt");
    if (!savefile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "failed to save";
           return;
    }
    QTextStream out(&savefile);
    out << cstack1.size()<<"\n";

   for(int c=0;c<cstack1.size();c++){
       out << "5\n";
    for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                out << cstack1[c].B[i][j] << "\n";
            }
        }
        out << cstack1[c].score <<"\n";
        out << "0\n" ;
        if(cstack1[c].movement==false)
        out << "0\n";
        else
            out << "1\n";
        if(cstack1[c].stat==false)
        out << "0\n";
        else
            out << "1\n";
        if(cstack1[c].ff==false)
        out << "0\n";
        else
            out << "1\n";
   }
}
void thegame5x5::loadgame(){

    QString siddu="/home/siddu/Downloads/gamepro/contents.txt";
    QString sunny="/home/yashwanth/Projects/gamepro/contents.txt";
    QFile file("contents.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
          qDebug() << "failed1 ";
           return;
        }
       cstack1.clear();
       QTextStream in(&file);
       QString line = in.readLine();
      // QTextStream in(&file);
       int size=line.toInt();
       for(int c=0;c<size;c++){
           Config1 temp;

             line = in.readLine(); // 4 5 6
             if(line!="5")
                qDebug()<<"failed : expected 5x5 "<<line<<"x"<<line<<endl;
       for(int i=0;i<5;i++)
           {
               for(int j=0;j<5;j++)
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
        ff1=true;
        temp.ff=true;
        }
        else
        {
            ff1=false;
            temp.ff=false;
        }
        cstack1.push_back(temp);
      }
       Config1 temp1=cstack1.top();
       int a=cstack1.size()-1;
       QString ss=QString::number(a);
       ui->undobutton->setText(ss);
       cstack1.pop();
       for(int i=0;i<5;i++)
           {
               for(int j=0;j<5;j++)
               {
                    Board1[i][j]=temp1.B[i][j];
               }
           }
       stat=temp1.stat;
       movement=temp1.movement;
       score=temp1.score;
       setscore(score);
       setpics();
       checkwin();
}
void thegame5x5::undogame(){
    if(!cstack1.empty())
    {
        Config1 temp=cstack1.top();
        cstack1.pop_back();
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                Board1[i][j]=temp.B[i][j];
        stat=temp.stat;
        movement=temp.movement;
        score=temp.score;
        setpics();
        setscore(score);
        int k=cstack1.size();
        QString ss=QString::number(k);
      //  QString s="Undo";
       // s=s+ss;
      //  ui->undobutton->setText(ss);
        checkwin();
    }
}
void thegame5x5::scorefile(){

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
void thegame5x5::saveHighscores(){

    QString siddu="/home/siddu/Downloads/gamepro/leaderboard.txt";
    QString sunny="/home/yashwanth/Projects/gamepro/leaderboard.txt";
    QFile file("leaderboard.txt");
       if (!file.open(QIODevice::WriteOnly))
       {
          qDebug() << "failed in savehighscores ";
           return;
        }
      Best[1]=highscore;
    QTextStream out(&file);
    out << Best[0] <<"\n";
    out << Best[1] <<"\n";
     out << Best[2] <<"\n";
}
void thegame5x5::seeHighscore(){

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
     line=in.readLine();
    highscore=line.toInt();
    ui->highscorelabel->setText(line);
    Best[0]=line.toInt();
    line=in.readLine();
    Best[1]=line.toInt();
    line=in.readLine();
     Best[2]=line.toInt();

}

thegame5x5::thegame5x5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thegame5x5)
{
    ui->setupUi(this);

    QString siddu="/home/siddu/Downloads/gamepro/images/2048_logo.svg";
    QString sunny=":/resources/images/2048_logo.svg";
    QPixmap pic(sunny);
    int w=ui->label_26->width();
    int h=ui->label_26->height();
    ui->label_26->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));
    //ui->label->resize(100,100);
    bool movement=true;
    Newgame();
    bool stat=false;
    randomizer(stat,movement);
    setscore(score);
    seeHighscore();
    setpics();
}

thegame5x5::~thegame5x5()
{
    delete ui;
}
void thegame5x5::keyPressEvent(QKeyEvent *event){
        thegame5x5::update(event);
}

void thegame5x5::on_undobutton_clicked()
{
    undogame();
    qDebug() << cstack1.size() <<"\n";
}

void thegame5x5::on_optionstab_clicked()
{
    setConfig1(Board1,stat,movement,score,0,ff);
    cstack1.push_back(config1);
        savegame();
        QApplication::exit();
}

void thegame5x5::on_pushButton_3_clicked()
{
    Newgame();
    stat=checkBoard();
    randomizer(stat,true);
    setpics();
    score=0;

    setscore(score);
    cstack1.clear();

}
