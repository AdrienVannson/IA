#include <QApplication>

#include <cstdio>

#include "UI/MainWindow.h"


int main (int argc, char *argv[])
{
    srand(42);

    QApplication application (argc, argv);

    MainWindow fenetrePrincipale;
    fenetrePrincipale.show();

    return application.exec();
}
