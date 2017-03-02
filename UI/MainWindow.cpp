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


    // Création d'une fausse partie (TODEL)
    Simulateur simulateur;
    Partie *partie = new Partie;

    SituationJeu sitPrecedante;
    sitPrecedante.initialiser();


    for (int iTour=0; iTour<100; iTour++) {
        const int idJoueur = iTour % 2;

        Action action;
        action.setType(Action::DEPLACEMENT);
        action.setIdJoueur(idJoueur);
        action.setInformation(0, 0); // Source
        action.setInformation(0, 1); // Cible
        action.setInformation(1, 2); // Nombre d'unités à envoyer

        for (unsigned int iUsine=0; iUsine<sitPrecedante.usines()->size(); iUsine++) {
            const SituationJeu::Usine &usine = (*sitPrecedante.usines())[iUsine];

            if (usine.m_proprietaire == idJoueur) {
                action.setInformation(iUsine, 0);
            }

            if (usine.m_production == !idJoueur) {
                action.setInformation(iUsine, 1);
            }
        }

        SituationJeu nouvelleSituation = simulateur.simulerAction(sitPrecedante, action);

        Tour tour;
        tour.setSituationJeu(nouvelleSituation);
        partie->addTour(tour);

        sitPrecedante = nouvelleSituation;
    }


    // Affichage d'une partie
    WidgetPartie *widgetPartie = new WidgetPartie;
    widgetPartie->afficherPartie(partie);

    QDockWidget *dockPartie = new QDockWidget("Partie", this);
    dockPartie->setWidget(widgetPartie);
    addDockWidget(Qt::RightDockWidgetArea, dockPartie);
}

MainWindow::~MainWindow ()
{

}
