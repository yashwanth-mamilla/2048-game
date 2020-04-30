#include "gameover.h"
#include "ui_gameover.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>

Gameover::Gameover(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gameover)
{
    ui->setupUi(this);
    QString siddu="/home/siddu/Downloads/gamepro/score.txt";
    QString sunny="/home/yashwanth/Projects/gamepro/score.txt";
    QFile file("score.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       qDebug() << "failed in gameover::class ";
        return;
     }
      QTextStream in(&file);
      QString ss=in.readLine();
      ui->label_3->setText(ss);
 //   ui11->label_3->setText(ss);
      qDebug()<< ss<<"\n";
}

Gameover::~Gameover()
{
    delete ui;
}
