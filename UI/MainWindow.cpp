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


    // Affichage des parties
    WidgetPartie *widgetPartie = new WidgetPartie;

    QDockWidget *dockPartie = new QDockWidget("Partie", this);
    dockPartie->setWidget(widgetPartie);
    addDockWidget(Qt::RightDockWidgetArea, dockPartie);


    // Connexion
    connect(m_partiesManagerWidget, &PartiesManagerWidget::partieSelectionnee, this, &MainWindow::afficherPartie);
    connect(this, &MainWindow::partieAffichee, widgetPartie, &WidgetPartie::afficherPartie);



    // Simulation de plusieurs parties
    Glouton1Factory fabrique;

    for (int iPartie=0; iPartie<100; iPartie++) {
        std::vector<Joueur*> joueurs;

        for (int iJoueur=0; iJoueur<iPartie%3+2; iJoueur++) {
            joueurs.push_back(fabrique.creerJoueur());
        }

        SituationJeu situationDepart (joueurs.size());

        for (unsigned int iJoueur=0; iJoueur<joueurs.size(); iJoueur++) {
            situationDepart.setPositionJoueur(iJoueur, rand()%(SituationJeu::NB_CELLULES));
        }

        Partie* partie = SimulateurPartie::simulerPartie(situationDepart, joueurs);
        m_partiesManager.addPartie(partie);

        for (unsigned int iJoueur=0; iJoueur<joueurs.size(); iJoueur++) {
            delete joueurs[iJoueur];
        }
    }

    m_partiesManagerWidget->actualiser();
}

MainWindow::~MainWindow ()
{

}


void MainWindow::afficherPartie (const int idPartie)
{
    Partie *partie = m_partiesManager.getPartie(idPartie);

    emit partieAffichee(partie);
}
