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
    m_partiesManagerWidget = new PartiesManagerWidget;
    m_partiesManagerWidget->setPartiesManager(&m_partiesManager);

    setCentralWidget(m_partiesManagerWidget);


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

        nouvelleSituation.setCellule(15-iTour, iTour, iTour%2 ? SituationJeu::JOUEUR_1 : SituationJeu::JOUEUR_2);

        Tour tour;
        tour.setSituationJeu(nouvelleSituation);
        partie2->addTour(tour);

        sitPrecedante = nouvelleSituation;
    }


    m_partiesManager.addPartie(partie1);
    m_partiesManager.addPartie(partie2);

    m_partiesManagerWidget->actualiser();


    // Affichage des parties
    WidgetPartie *widgetPartie = new WidgetPartie;
    widgetPartie->afficherPartie(partie1);


    QDockWidget *dockPartie = new QDockWidget("Partie", this);
    dockPartie->setWidget(widgetPartie);
    addDockWidget(Qt::RightDockWidgetArea, dockPartie);


    // Connexion
    connect(m_partiesManagerWidget, &PartiesManagerWidget::partieSelectionnee, this, &MainWindow::afficherPartie);
    connect(this, &MainWindow::partieAffichee, widgetPartie, &WidgetPartie::afficherPartie);


    // Simulation d'une partie
    Glouton1Factory fabrique;

    std::vector<Joueur*> joueurs;

    joueurs.push_back(fabrique.creerJoueur());
    joueurs.push_back(fabrique.creerJoueur());

    SituationJeu situationDepart (joueurs.size());

    for (unsigned int iJoueur=0; iJoueur<joueurs.size(); iJoueur++) {
        situationDepart.setPositionJoueur(iJoueur, rand()%(SituationJeu::NB_CELLULES));
    }

    Partie* partie = SimulateurPartie::simulerPartie(situationDepart, joueurs);
    m_partiesManager.addPartie(partie);

    m_partiesManagerWidget->actualiser();

    delete joueurs[0];
    delete joueurs[1];
}

MainWindow::~MainWindow ()
{

}


void MainWindow::afficherPartie (const int idPartie)
{
    Partie *partie = m_partiesManager.getPartie(idPartie);

    emit partieAffichee(partie);
}
