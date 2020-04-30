#ifndef THEGAME_H
#define THEGAME_H
#include <QMainWindow>
#include "gameover.h"
#include "gamewin.h"
QT_BEGIN_NAMESPACE
namespace Ui { class thegame; }
QT_END_NAMESPACE

class thegame : public QMainWindow
{
    Q_OBJECT

public:
    thegame(QWidget *parent = nullptr);

    void Newgame();
    void keyPressEvent(QKeyEvent*);
   // void setConfig(bool ,bool ,int ,int );
    void PrintBoard();
    bool checkBoard();
    int Board[4][4];
    bool movement;
    bool stat;
    int highscore;
    int Best[3];
    int score;
    bool ff=false;
    bool completeboard();
    void randomizer(bool,bool);
    void update(QKeyEvent*);
    void checkwin();
    void setpics();
    void setscore(int);
    void savegame();
    void loadgame();
    void undogame();
    void scorefile();
    void saveHighscores();
    void seeHighscore();
   // void playsound();
    ~thegame();

private slots:


    void on_pushButton_3_clicked();

    void on_optionstab_clicked();

    void on_undobutton_clicked();

private:
    Ui::thegame *ui;
    Gameover *gover;
    gamewin *gwin;
};
#endif // THEGAME_H
