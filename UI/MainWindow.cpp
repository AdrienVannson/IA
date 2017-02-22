#include "MainWindow.h"

MainWindow::MainWindow (QWidget *parent) :
    QMainWindow(parent)
{
    // Menu
    QMenu *menuFichier = menuBar()->addMenu(tr("Fichier"));

    QAction *actionQuitter = new QAction(tr("Quitter"), this);
    connect(actionQuitter, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

    menuFichier->addAction(actionQuitter);

    QPushButton *boutton = new QPushButton("Commencer l'entrainement");
    setCentralWidget(boutton);
}

MainWindow::~MainWindow ()
{

}
