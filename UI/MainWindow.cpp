#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QLabel *label = new QLabel("Bienvenue dans l'entraineur d'IAs.");
    label->setAlignment(Qt::AlignCenter);
    setCentralWidget(label);
}

MainWindow::~MainWindow()
{

}
