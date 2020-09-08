#include "mainwindow.h"
#include "welcomedialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WelcomeDialog g;
    MainWindow w;
    w.show();
    g.show();


    return a.exec();
}
