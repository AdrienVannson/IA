#include "UI/MainWindow.h"
#include <QApplication>

int main (int argc, char *argv[])
{
    QApplication application(argc, argv);
    MainWindow fenetrePrincipale;
    fenetrePrincipale.show();

    return application.exec();
}
