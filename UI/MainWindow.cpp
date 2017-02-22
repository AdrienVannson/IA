#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QPushButton *boutton = new QPushButton("Commencer l'entrainement");
    setCentralWidget(boutton);
}

MainWindow::~MainWindow()
{

}
