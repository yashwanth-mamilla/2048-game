#include "thegame.h"
#include "intro.h"
#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir::setCurrent(qApp->applicationDirPath());
    intro v;
    v.show();
   // w.show();
    return a.exec();
}
