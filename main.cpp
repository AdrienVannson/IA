#include <string>

#include <QApplication>

#include "UI/MainWindow.hpp"


int main (int argc, char *argv[])
{
    QApplication application (argc, argv);

    qRegisterMetaType<std::string>("string");

    MainWindow fenetrePrincipale;
    fenetrePrincipale.show();

    return application.exec();
}
