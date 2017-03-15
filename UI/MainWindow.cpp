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
    QPushButton *boutton = new QPushButton("Bienvenue");
    setCentralWidget(boutton);


    // Création d'une fausse partie (TODEL)
    Partie *partie = new Partie;

    SituationJeu sitPrecedante;

    for (int iTour=0; iTour<15; iTour++) {
        SituationJeu nouvelleSituation(sitPrecedante);

        nouvelleSituation.setCellule(iTour, 1 + 2*iTour, SituationJeu::JOUEUR_1);

        Tour tour;
        tour.setSituationJeu(nouvelleSituation);
        partie->addTour(tour);

        sitPrecedante = nouvelleSituation;
    }


    // Affichage des parties
    WidgetPartie *widgetPartie = new WidgetPartie;
    widgetPartie->afficherPartie(partie);

    QDockWidget *dockPartie = new QDockWidget("Partie", this);
    dockPartie->setWidget(widgetPartie);
    addDockWidget(Qt::RightDockWidgetArea, dockPartie);
}

MainWindow::~MainWindow ()
{

}
