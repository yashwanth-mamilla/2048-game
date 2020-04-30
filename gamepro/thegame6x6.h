#ifndef THEGAME6X6_H
#define THEGAME6X6_H

#include <QDialog>
#include"gameover.h"
#include "gamewin.h"
namespace Ui {
class thegame6x6;
}

class thegame6x6 : public QDialog
{
    Q_OBJECT

public:
    explicit thegame6x6(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent*);
    void Newgame();
  // void setConfig(bool ,bool ,int ,int );
   void PrintBoard();
   bool checkBoard();
   void checkwin();
   int Board2[6][6];
   bool ff;
   bool movement;
   bool stat;
   int highscore;
   int Best[3];
   int score;
   bool completeboard();
   void randomizer(bool,bool);
   void update(QKeyEvent*);
   void setpics();
   void setscore(int);
   void savegame();
   void loadgame();
   void undogame();
   void scorefile();
   void saveHighscores();
   void seeHighscore();

    ~thegame6x6();

private slots:
   void on_undobutton_2_clicked();

   void on_optionstab_2_clicked();

   void on_pushButton_3_clicked();

private:
    Ui::thegame6x6 *ui;
    Gameover *gover;
    gamewin *gwin;
};

#endif // THEGAME6X6_H
