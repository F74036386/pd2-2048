#include "game.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game w;
    w.setMaximumSize(600,600);
    w.setMinimumSize(600,600);
    w.show();

    return a.exec();
}
