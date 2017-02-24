#include "MainWindow.h"

MainWindow::MainWindow (QWidget *parent) :
    QMainWindow(parent)
{
    showMaximized();

    // Menu
    QMenu *menuFichier = menuBar()->addMenu(tr("Fichier"));

    QAction *actionQuitter = new QAction(tr("Quitter"), this);
    connect(actionQuitter, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

    menuFichier->addAction(actionQuitter);


    // Contenu de la fenêtre
    QPushButton *boutton = new QPushButton("Commencer l'entrainement");
    setCentralWidget(boutton);


    // Affichage d'une partie
    WidgetPartie *widgetPartie = new WidgetPartie;

    QDockWidget *dockPartie = new QDockWidget("Partie", this);
    dockPartie->setWidget(widgetPartie);
    addDockWidget(Qt::RightDockWidgetArea, dockPartie);
}

MainWindow::~MainWindow ()
{

}
