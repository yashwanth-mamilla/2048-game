#ifndef THEGAME5X5_H
#define THEGAME5X5_H

#include <QDialog>
#include "gameover.h"
#include"gamewin.h"
namespace Ui {
class thegame5x5;
}

class thegame5x5 : public QDialog
{
    Q_OBJECT

public:
    explicit thegame5x5(QWidget *parent = nullptr);
    void Newgame();
   void keyPressEvent(QKeyEvent*);
   // void setConfig(bool ,bool ,int ,int );
    void PrintBoard();
    bool checkBoard();
    void checkwin();
    int Board1[5][5];
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

    ~thegame5x5();

private slots:
    void on_undobutton_clicked();

    void on_optionstab_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::thegame5x5 *ui;
    Gameover *gover;
    gamewin *gwin;
};

#endif // THEGAME5X5_H
