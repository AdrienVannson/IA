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
    Partie *partie1 = new Partie;
    SituationJeu sitPrecedante;

    for (int iTour=0; iTour<15; iTour++) {
        SituationJeu nouvelleSituation(sitPrecedante);

        nouvelleSituation.setCellule(iTour, 1 + 2*iTour, SituationJeu::JOUEUR_1);

        Tour tour;
        tour.setSituationJeu(nouvelleSituation);
        partie1->addTour(tour);

        sitPrecedante = nouvelleSituation;
    }


    Partie *partie2 = new Partie;
    sitPrecedante = SituationJeu ();

    for (int iTour=0; iTour<15; iTour++) {
        SituationJeu nouvelleSituation(sitPrecedante);

        nouvelleSituation.setCellule(15-iTour, iTour, SituationJeu::JOUEUR_1);

        Tour tour;
        tour.setSituationJeu(nouvelleSituation);
        partie2->addTour(tour);

        sitPrecedante = nouvelleSituation;
    }


    m_partiesManager.addPartie(partie1);
    m_partiesManager.addPartie(partie2);


    // Affichage des parties
    WidgetPartie *widgetPartie = new WidgetPartie;
    widgetPartie->afficherPartie(partie1);


    QDockWidget *dockPartie = new QDockWidget("Partie", this);
    dockPartie->setWidget(widgetPartie);
    addDockWidget(Qt::RightDockWidgetArea, dockPartie);
}

MainWindow::~MainWindow ()
{

}
