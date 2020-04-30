#include "thegame6x6.h"
#include "ui_thegame6x6.h"
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
int Board2[6][6];
int ccc=0;
bool ff2=false;
class Config2{
public:
    int B[6][6];
    bool stat;
    bool movement;
    int score;
    int highscore;
    int ff;
};
Config2 config2;
QStack< Config2 > cstack2;
void setConfig2(bool Stat,bool Movement,int Score,int Highscore,bool ff)
{
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
            config2.B[i][j]=Board2[i][j];
    config2.stat=Stat;
    config2.movement=Movement;
    config2.score=Score;
    config2.highscore=Highscore;
    config2.ff=ff;
}
void thegame6x6::setscore(int score){
    std::stringstream s;
    s << score ;
    std::string a=s.str();
    QString ss =QString::fromStdString(a);
    ui->label_41->setText(ss);

    if(score>highscore){
        ui->highscorelabel_2->setText(ss);
        highscore=score;
    }
    QString sk="Undo";
            //sk=sk+QString::number(cstack.size());

    ui->undobutton_2->setText(sk);
    ui->undobutton_2->setStyleSheet("background: rgb( 245, 176, 65 );color: rgb(119,110,101); font: bold;font: 15pt;border-color: rgb(220, 118, 51);border-width:2.5px;border-style:outset;");
    if(cstack2.size()==0)
    {
        ui->undobutton_2->setStyleSheet("background: rgb( 245, 176, 65 );color: rgb(119,110,101); font: bold;font: 15pt;");
    }

}
void thegame6x6::randomizer(bool status,bool m){
    if(!m)
        return;
    if(status==false)
    {
        int i,j;
        i=rand()%6;
        j=rand()%6;
        while(Board2[i][j]!=0)
        {
            i=rand()%6;
            j=rand()%6;

        }
        if(ccc!=10)
        {Board2[i][j]=2;
            ccc++;
        }
        else
        {
            Board2[i][j]=4;
            ccc=0;
        }
        movement=false;
    }
}
bool thegame6x6::checkBoard(){
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(Board2[i][j]==0)
                return false;
        }
    }
    return true;
}
void thegame6x6::checkwin(){
    qDebug()<<" ff "<<ff<<endl;
    if(ff2==true)
        return;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(Board2[i][j]==2048)
            {
                //hide();
                qDebug()<< "win "<<ff2<<endl;
                gwin=new gamewin(this);

                gwin->show();
                ff=true;
                ff2=true;
                return ;
            }
        }
    }
}

bool thegame6x6::completeboard(){

    for(int i=0;i<5;i++)
    {
        for(int j=1;j<6;j++)
        {
            if(Board2[i][j-1]==Board2[i][j])
                return false;
            if(Board2[i][j]==Board2[i+1][j])
                return false;
        }
    }
    for(int i=0;i<5;i++)
    {
        if(Board2[i][0]==Board2[i+1][0])
        return false;
        if(Board2[5][i]==Board2[5][i+1])
        return false;
    }
    return true;
}
void thegame6x6::Newgame(){
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            Board2[i][j]=0;
        }
    }
    score=0;
}
void thegame6x6::update(QKeyEvent* event1)
{
        if(event1->key()==Qt::Key_A)
        {
            setConfig2(stat,movement,score,0,ff);
            if(cstack2.size()<5)
            cstack2.push_back(config2);
            if(cstack2.size()>=5)
           {
                cstack2.pop_front();
                cstack2.push_back(config2);
            }
            for(int i=0;i<6;i++)
            {
                for(int j=5;j>0;j--)
                {
                    if(Board2[i][j-1]==0 && Board2[i][j]!=0)
                    {
                        Board2[i][j-1]=Board2[i][j];
                        Board2[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=5;j>0;j--)
                {
                    if(Board2[i][j-1]==0 && Board2[i][j]!=0)
                    {
                        Board2[i][j-1]=Board2[i][j];
                        Board2[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=5;j>0;j--)
                {
                    if(Board2[i][j-1]==0 && Board2[i][j]!=0)
                    {
                        Board2[i][j-1]=Board2[i][j];
                        Board2[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=5;j>0;j--)
                {
                    if(Board2[i][j-1]==0 && Board2[i][j]!=0)
                    {
                        Board2[i][j-1]=Board2[i][j];
                        Board2[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=5;j>0;j--)
                {
                    if(Board2[i][j-1]==0 && Board2[i][j]!=0)
                    {
                        Board2[i][j-1]=Board2[i][j];
                        Board2[i][j]=0;
                        movement=true;
                    }
                }

                for(int j=0;j<5;j++)
                {
                    if(Board2[i][j+1]==Board2[i][j] && Board2[i][j]!=0)
                    {
                        score+= Board2[i][j];
                        Board2[i][j] *= 2;
                        Board2[i][j+1]=0;
                        movement=true;

                    }
                }
                for(int j=5;j>0;j--)
                {
                    if(Board2[i][j-1]==0 && Board2[i][j]!=0)
                    {
                        Board2[i][j-1]=Board2[i][j];
                        Board2[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=5;j>0;j--)
                {
                    if(Board2[i][j-1]==0 && Board2[i][j]!=0)
                    {
                        Board2[i][j-1]=Board2[i][j];
                        Board2[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=5;j>0;j--)
                {
                    if(Board2[i][j-1]==0 && Board2[i][j]!=0)
                    {
                        Board2[i][j-1]=Board2[i][j];
                        Board2[i][j]=0;
                        movement=true;
                    }
                }
            }
            setscore(score);
            stat=checkBoard();
            randomizer(stat,movement);
            setpics();
            checkwin();
            stat=checkBoard();
            if(stat){
                if(completeboard())
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
            setConfig2(stat,movement,score,0,ff);
            if(cstack2.size()<5)
            cstack2.push_back(config2);
            if(cstack2.size()>=5)
            {
                cstack2.pop_front();
                cstack2.push_back(config2);
            }
            for(int i=0;i<6;i++)
            {
                for(int j=0;j<5;j++)
                {
                    if(Board2[i][j+1]==0 && Board2[i][j]!=0)
                    {
                        Board2[i][j+1]=Board2[i][j];
                        Board2[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<5;j++)
                {
                    if(Board2[i][j+1]==0 && Board2[i][j]!=0)
                    {
                        Board2[i][j+1]=Board2[i][j];
                        Board2[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<5;j++)
                {
                    if(Board2[i][j+1]==0 && Board2[i][j]!=0)
                    {
                        Board2[i][j+1]=Board2[i][j];
                        Board2[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<5;j++)
                {
                    if(Board2[i][j+1]==0 && Board2[i][j]!=0)
                    {
                        Board2[i][j+1]=Board2[i][j];
                        Board2[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<5;j++)
                {
                    if(Board2[i][j+1]==0 && Board2[i][j]!=0)
                    {
                        Board2[i][j+1]=Board2[i][j];
                        Board2[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=5;j>0;j--)
                {
                    if(Board2[i][j-1]==Board2[i][j] && Board2[i][j]!=0)
                    {
                        score+=Board2[i][j-1];
                        Board2[i][j] *= 2;
                        Board2[i][j-1]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<5;j++)
                {
                    if(Board2[i][j+1]==0 && Board2[i][j]!=0)
                    {
                        Board2[i][j+1]=Board2[i][j];
                        Board2[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<5;j++)
                {
                    if(Board2[i][j+1]==0 && Board2[i][j]!=0)
                    {
                        Board2[i][j+1]=Board2[i][j];
                        Board2[i][j]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<5;j++)
                {
                    if(Board2[i][j+1]==0 && Board2[i][j]!=0)
                    {
                        Board2[i][j+1]=Board2[i][j];
                        Board2[i][j]=0;
                        movement=true;
                    }
                }
            }
            setscore(score);
            stat=checkBoard();
            randomizer(stat,movement);
            setpics();
            checkwin();
            stat=checkBoard();
            if(stat){
                if(completeboard())
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
            setConfig2(stat,movement,score,0,ff);
            if(cstack2.size()<5)
            cstack2.push_back(config2);
            if(cstack2.size()>=5)
            {
                cstack2.pop_front();
                cstack2.push_back(config2);
            }
            for(int i=0;i<6;i++){
                for(int j=5;j>0;j--)
                {
                    if(Board2[j-1][i]==0 && Board2[j][i]!=0)
                    {
                        Board2[j-1][i]=Board2[j][i];
                        Board2[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=5;j>0;j--)
                {
                    if(Board2[j-1][i]==0 && Board2[j][i]!=0)
                    {
                        Board2[j-1][i]=Board2[j][i];
                        Board2[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=5;j>0;j--)
                {
                    if(Board2[j-1][i]==0 && Board2[j][i]!=0)
                    {
                        Board2[j-1][i]=Board2[j][i];
                        Board2[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=5;j>0;j--)
                {
                    if(Board2[j-1][i]==0 && Board2[j][i]!=0)
                    {
                        Board2[j-1][i]=Board2[j][i];
                        Board2[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=5;j>0;j--)
                {
                    if(Board2[j-1][i]==0 && Board2[j][i]!=0)
                    {
                        Board2[j-1][i]=Board2[j][i];
                        Board2[j][i]=0;
                        movement=true;
                    }
                }


                for(int j=0;j<5;j++)
                {
                    if(Board2[j+1][i]==Board2[j][i] && Board2[j][i]!=0)
                    {
                        score+=Board2[j][i];
                        Board2[j][i] *= 2;
                        Board2[j+1][i]=0;
                        movement=true;
                    }
                }
                for(int j=5;j>0;j--)
                {
                    if(Board2[j-1][i]==0 && Board2[j][i]!=0)
                    {
                        Board2[j-1][i]=Board2[j][i];
                        Board2[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=5;j>0;j--)
                {
                    if(Board2[j-1][i]==0 && Board2[j][i]!=0)
                    {
                        Board2[j-1][i]=Board2[j][i];
                        Board2[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=5;j>0;j--)
                {
                    if(Board2[j-1][i]==0 && Board2[j][i]!=0)
                    {
                        Board2[j-1][i]=Board2[j][i];
                        Board2[j][i]=0;
                        movement=true;
                    }
                }
            }
            setscore(score);
            stat=checkBoard();
            randomizer(stat,movement);
            setpics();
            checkwin();
            stat=checkBoard();
            if(stat){
                if(completeboard())
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
            setConfig2(stat,movement,score,0,ff);
            if(cstack2.size()<5)
            cstack2.push_back(config2);
            if(cstack2.size()>=5)
            {
                cstack2.pop_front();
                cstack2.push_back(config2);
            }
            for(int i=0;i<6;i++){
                for(int j=0;j<5;j++)
                {
                    if(Board2[j+1][i]==0 && Board2[j][i]!=0)
                    {
                        Board2[j+1][i]=Board2[j][i];
                        Board2[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<5;j++)
                {
                    if(Board2[j+1][i]==0 && Board2[j][i]!=0)
                    {
                        Board2[j+1][i]=Board2[j][i];
                        Board2[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<5;j++)
                {
                    if(Board2[j+1][i]==0 && Board2[j][i]!=0)
                    {
                        Board2[j+1][i]=Board2[j][i];
                        Board2[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<5;j++)
                {
                    if(Board2[j+1][i]==0 && Board2[j][i]!=0)
                    {
                        Board2[j+1][i]=Board2[j][i];
                        Board2[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<5;j++)
                {
                    if(Board2[j+1][i]==0 && Board2[j][i]!=0)
                    {
                        Board2[j+1][i]=Board2[j][i];
                        Board2[j][i]=0;
                        movement=true;
                    }
                }


                for(int j=5;j>0;j--)
                {
                    if(Board2[j-1][i]==Board2[j][i] && Board2[j][i]!=0)
                    {
                        score+=Board2[j-1][i];
                        Board2[j][i] *= 2;
                        Board2[j-1][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<5;j++)
                {
                    if(Board2[j+1][i]==0 && Board2[j][i]!=0)
                    {
                        Board2[j+1][i]=Board2[j][i];
                        Board2[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<5;j++)
                {
                    if(Board2[j+1][i]==0 && Board2[j][i]!=0)
                    {
                        Board2[j+1][i]=Board2[j][i];
                        Board2[j][i]=0;
                        movement=true;
                    }
                }
                for(int j=0;j<5;j++)
                {
                    if(Board2[j+1][i]==0 && Board2[j][i]!=0)
                    {
                        Board2[j+1][i]=Board2[j][i];
                        Board2[j][i]=0;
                        movement=true;
                    }
                }
            }
            setscore(score);
            stat=checkBoard();
            randomizer(stat,movement);
            setpics();
            checkwin();
            stat=checkBoard();
            if(stat){
                if(completeboard())
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
void thegame6x6::setpics(){

   int k=Board2[0][0];
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
      ui->label_1->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_1->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_1->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[0][1];
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
      ui->label_2->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_2->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_2->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[0][2];
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
      ui->label_3->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_3->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_3->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[0][3];
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
      ui->label_4->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_4->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_4->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[0][4];
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
      ui->label_5->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_5->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_5->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[0][5];
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
      ui->label_6->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_6->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_6->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[1][0];
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
      ui->label_7->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_7->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_7->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[1][1];
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
      ui->label_8->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_8->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_8->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[1][2];
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
      ui->label_9->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_9->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_9->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[1][3];
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
      ui->label_10->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_10->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_10->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[1][4];
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
      ui->label_11->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_11->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_11->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[1][5];
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
      ui->label_12->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_12->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_12->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[2][0];
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
      ui->label_13->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_13->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_13->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[2][1];
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
      ui->label_14->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_14->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_14->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[2][2];
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
      ui->label_15->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_15->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_15->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[2][3];
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
      ui->label_16->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_16->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_16->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[2][4];
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
      ui->label_17->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_17->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_17->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[2][5];
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
      ui->label_18->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_18->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_18->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");

    k=Board2[3][0];
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
      ui->label_19->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_19->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_19->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[3][1];
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
      ui->label_20->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_20->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_20->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[3][2];
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
      ui->label_21->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_21->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_21->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[3][3];
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
      ui->label_22->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_22->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_22->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[3][4];
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
      ui->label_23->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_23->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_23->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[3][5];
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
      ui->label_24->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_24->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_24->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[4][0];
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
      ui->label_25->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_25->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_25->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[4][1];
     s= QString::number(k);
    if(k>0)
    ui->label_26->setText(s);
    if(k==0){
    ui->label_26->setText("");
    ui->label_26->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_26->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_26->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_26->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_26->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_26->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_26->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_26->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_26->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_26->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_26->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_26->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_26->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[4][2];
     s= QString::number(k);
    if(k>0)
    ui->label_27->setText(s);
    if(k==0){
    ui->label_27->setText("");
    ui->label_27->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_27->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_27->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_27->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_27->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_27->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_27->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_27->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_27->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_27->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_27->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_27->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_27->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[4][3];
     s= QString::number(k);
    if(k>0)
    ui->label_28->setText(s);
    if(k==0){
    ui->label_28->setText("");
    ui->label_28->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_28->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_28->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_28->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_28->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_28->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_28->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_28->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_28->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_28->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_28->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_28->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_28->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[4][4];
     s= QString::number(k);
    if(k>0)
    ui->label_29->setText(s);
    if(k==0){
    ui->label_29->setText("");
    ui->label_29->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_29->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_29->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_29->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_29->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_29->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_29->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_29->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_29->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_29->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_29->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_29->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_29->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[4][5];
     s= QString::number(k);
    if(k>0)
    ui->label_30->setText(s);
    if(k==0){
    ui->label_30->setText("");
    ui->label_30->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_30->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_30->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_30->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_30->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_30->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_30->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_30->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_30->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_30->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_30->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_30->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_30->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[5][0];
     s= QString::number(k);
    if(k>0)
    ui->label_31->setText(s);
    if(k==0){
    ui->label_31->setText("");
    ui->label_31->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_31->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_31->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_31->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_31->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_31->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_31->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_31->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_31->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_31->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_31->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_31->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_31->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[5][1];
     s= QString::number(k);
    if(k>0)
    ui->label_32->setText(s);
    if(k==0){
    ui->label_32->setText("");
    ui->label_32->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_32->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_32->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_32->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_32->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_32->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_32->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_32->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_32->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_32->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_32->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_32->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_32->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[5][2];
     s= QString::number(k);
    if(k>0)
    ui->label_33->setText(s);
    if(k==0){
    ui->label_33->setText("");
    ui->label_33->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_33->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_33->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_33->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_33->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_33->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_33->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_33->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_33->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_33->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_33->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_33->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_33->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[5][3];
     s= QString::number(k);
    if(k>0)
    ui->label_34->setText(s);
    if(k==0){
    ui->label_34->setText("");
    ui->label_34->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_34->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_34->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_34->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_34->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_34->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_34->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_34->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_34->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_34->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_34->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_34->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_34->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[5][4];
     s= QString::number(k);
    if(k>0)
    ui->label_35->setText(s);
    if(k==0){
    ui->label_35->setText("");
    ui->label_35->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_35->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_35->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_35->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_35->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_35->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_35->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_35->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_35->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_35->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_35->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_35->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_35->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");


     k=Board2[5][5];
     s= QString::number(k);
    if(k>0)
    ui->label_36->setText(s);
    if(k==0){
    ui->label_36->setText("");
    ui->label_36->setStyleSheet(" background: rgb(204,192,179); border-radius: 10px; ");
    }
    if(k==2)
      ui->label_36->setStyleSheet(" background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==4)
      ui->label_36->setStyleSheet(" background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==8)
      ui->label_36->setStyleSheet(" background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==16)
      ui->label_36->setStyleSheet(" background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==32)
      ui->label_36->setStyleSheet(" background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==64)
      ui->label_36->setStyleSheet(" background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==128)
      ui->label_36->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==256)
      ui->label_36->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==512)
      ui->label_36->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; ");
    if(k==1024)
      ui->label_36->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k==2048)
      ui->label_36->setStyleSheet(" background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 30pt; ");
    if(k>2048)
      ui->label_36->setStyleSheet("  background: rgb(52, 235, 91); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 30pt; ");
}
void thegame6x6::savegame(){
    QString siddu="/home/siddu/Downloads/gamepro/contents.txt";
    QString sunny="/home/yashwanth/Projects/gamepro/contents.txt";
    QFile savefile("contents.txt");
    if (!savefile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "failed to save";
           return;
    }
    QTextStream out(&savefile);
    out << cstack2.size()<<"\n";

   for(int c=0;c<cstack2.size();c++){
       out << "6\n";
    for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                out << cstack2[c].B[i][j] << "\n";
            }
        }
        out << cstack2[c].score <<"\n";
        out << "0\n" ;
        if(cstack2[c].movement==false)
        out << "0\n";
        else
            out << "1\n";
        if(cstack2[c].stat==false)
        out << "0\n";
        else
            out << "1\n";
        if(cstack2[c].ff==false)
            out<< "0\n";
        else
            out << "1\n";
   }
}
void thegame6x6::loadgame(){
    QString siddu="/home/siddu/Downloads/gamepro/contents.txt";
    QString sunny="/home/yashwanth/Projects/gamepro/leaderboard.txt";
    QFile file("contents.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
          qDebug() << "failed1 ";
           return;
        }
       cstack2.clear();
       QTextStream in(&file);
       QString line = in.readLine();
      // QTextStream in(&file);
       int size=line.toInt();
       for(int c=0;c<size;c++){
           Config2 temp;

             line = in.readLine(); // 4 5 6

       for(int i=0;i<6;i++)
           {
               for(int j=0;j<6;j++)
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
        ff2=true;
        temp.ff=true;
        }
        else
        {
            ff2=false;
            temp.ff=false;
        }
        cstack2.push_back(temp);

      }
       Config2 temp1=cstack2.top();
       int a=cstack2.size()-1;
       QString ss=QString::number(a);
       ui->undobutton_2->setText(ss);
       cstack2.pop();
       for(int i=0;i<6;i++)
           {
               for(int j=0;j<6;j++)
               {
                    Board2[i][j]=temp1.B[i][j];
               }
           }
       stat=temp1.stat;
       movement=temp1.movement;
       score=temp1.score;
       setscore(score);
       setpics();
       checkwin();
}
void thegame6x6::undogame(){
    if(!cstack2.empty())
    {
        Config2 temp=cstack2.top();
        cstack2.pop_back();
        for(int i=0;i<6;i++)
            for(int j=0;j<6;j++)
                Board2[i][j]=temp.B[i][j];
        stat=temp.stat;
        movement=temp.movement;
        score=temp.score;
        setpics();
        setscore(score);
        int k=cstack2.size();
        QString ss=QString::number(k);
      //  QString s="Undo";
       // s=s+ss;
       // ui->undobutton_2->setText(ss);
    }
}
void thegame6x6::scorefile(){
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
void thegame6x6::saveHighscores(){
    QString siddu="/home/siddu/Downloads/gamepro/leaderboard.txt";
    QString sunny="/home/yashwanth/Projects/gamepro/leaderboard.txt";
    QFile file("leaderboard.txt");
       if (!file.open(QIODevice::WriteOnly))
       {
          qDebug() << "failed in savehighscores ";
           return;
        }
      Best[2]=highscore;
    QTextStream out(&file);
    out << Best[0] <<"\n";
    out << Best[1] <<"\n";
     out << Best[2] <<"\n";
}
void thegame6x6::seeHighscore(){
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
     line=in.readLine();
    highscore=line.toInt();
    ui->highscorelabel_2->setText(line);
    Best[0]=line.toInt();
    line=in.readLine();
    Best[1]=line.toInt();
    line=in.readLine();
     Best[2]=line.toInt();

}
thegame6x6::thegame6x6(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thegame6x6)
{
    ui->setupUi(this);
    QString siddu="/home/siddu/Downloads/gamepro/images/2048_logo.svg";
    QString sunny=":/resources/images/2048_logo.svg";
    QPixmap pic(sunny);
    int w=ui->label_37->width();
    int h=ui->label_37->height();
    ui->label_37->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));
    //ui->label->resize(100,100);
    bool movement=true;
    Newgame();
    bool stat=false;
    randomizer(stat,movement);
    setscore(score);
    seeHighscore();
    setpics();

}

thegame6x6::~thegame6x6()
{
    delete ui;
}
void thegame6x6::keyPressEvent(QKeyEvent *event){
        thegame6x6::update(event);
}

void thegame6x6::on_undobutton_2_clicked()
{

    undogame();
    qDebug() << cstack2.size() <<"\n";

}

void thegame6x6::on_optionstab_2_clicked()
{
    setConfig2(stat,movement,score,0,ff);
    cstack2.push_back(config2);
        savegame();
        QApplication::exit();

}

void thegame6x6::on_pushButton_3_clicked()
{
    Newgame();
    stat=checkBoard();
    randomizer(stat,true);
    setpics();
    score=0;

    setscore(score);
    cstack2.clear();

}
