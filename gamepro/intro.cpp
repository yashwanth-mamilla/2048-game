#include "intro.h"
#include "ui_intro.h"
#include "thegame.h"
#include <iostream>
#include <fstream>
#include <QTextStream>
#include <QPixmap>
#include <QDebug>
#include <QSound>
#include <QFile>
QSound pop1("/home/yashwanth/Projects/gamepro/pop.mp3");
intro::intro(QWidget *parent) :
    QDialog(parent),
    ui1(new Ui::intro)
{
    ui1->setupUi(this);
    QString siddu="/home/siddu/Downloads/gamepro/images/2048_logo.svg";
    QString sunny=":/resources/images/2048_logo.svg";

    QPixmap pic(sunny);
    int w=ui1->introlabel->width();
    int h=ui1->introlabel->height();
    ui1->introlabel->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));
    ui1->layoutWidget->layout();

}

intro::~intro()
{
    delete ui1;
}

void intro::on_pushButton_clicked()
{
    pop1.play();
    hide();
    sl =new selectlevel(this);
    sl->show();


}

void intro::on_pushButton_4_clicked()
{
    pop1.play();
    QApplication::exit();
}


void intro::on_pushButton_2_clicked()
{
    pop1.play();
//    std::ifstream lfile;
//    lfile.open("contents.txt");
//    std::string ss;
//    getline(lfile,ss);
    QString siddu="/home/siddu/Downloads/gamepro/contents.txt";
    QString sunny="/home/yashwanth/Projects/gamepro/contents.txt";
    QFile file("contents.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       qDebug() << "failed in intro.ui load game opener \n";
        return;
     }
    QTextStream in(&file);
    QString line=in.readLine();
    if(line=="0")
        ui1->pushButton_2->setStyleSheet("background: rgb(179, 152, 121); color: rgb(36, 25, 12); font: bold; border-radius: 10px; font: 18pt;Border-width:2px;");
    line=in.readLine();
    if(line=="4")
    {
    hide();

        Thegame = new thegame(this);
        Thegame->loadgame();
        Thegame->show();
    }
    if(line=="5")
    {
        hide();

            Thegame5x5 = new thegame5x5(this);
            Thegame5x5->loadgame();
            Thegame5x5->show();
    }
    if(line=="6")
    {
        hide();

            Thegame6x6 = new thegame6x6(this);
            Thegame6x6->loadgame();
            Thegame6x6->show();


    }
}

void intro::on_pushButton_3_clicked()
{
    hide();
    pop1.play();
    pop1.stop();
    instructions = new Instructions(this);
    instructions->show();
}
