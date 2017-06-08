#include "MainWindow.h"

MainWindow::MainWindow (QWidget *parent) :
    QMainWindow(parent)
{
    showMaximized();

    m_joueursManager = new JoueursManager;
    m_partiesManager = new PartiesManager;

    // Menu
    QMenu *menuFichier = menuBar()->addMenu(tr("Fichier"));

    QAction *actionQuitter = new QAction(tr("Quitter"), this);
    connect(actionQuitter, &QAction::triggered, qApp, &QApplication::quit);

    menuFichier->addAction(actionQuitter);


    // Boutton
    QPushButton *boutton = new QPushButton ("Salut :)");
    setCentralWidget(boutton);



    // Affichage des parties
    m_partiesManagerWidget = new PartiesManagerWidget;
    m_partiesManagerWidget->setPartiesManager(m_partiesManager);
    connect(m_partiesManager, &PartiesManager::updated, m_partiesManagerWidget, &PartiesManagerWidget::actualiser);

    QDockWidget *dockParties = new QDockWidget("Parties", this);
    dockParties->setWidget(m_partiesManagerWidget);
    addDockWidget(Qt::RightDockWidgetArea, dockParties);


    // Affichage des joueurs
    m_joueursManagerWidget = new JoueursManagerWidget;
    m_joueursManagerWidget->setJoueursManager(m_joueursManager);

    QDockWidget *dockJoueurs = new QDockWidget("Joueurs", this);
    dockJoueurs->setWidget(m_joueursManagerWidget);
    addDockWidget(Qt::RightDockWidgetArea, dockJoueurs);


    // Affichage d'une partie
    WidgetPartie *widgetPartie = new WidgetPartie;

    QDockWidget *dockPartie = new QDockWidget("Partie", this);
    dockPartie->setWidget(widgetPartie);
    addDockWidget(Qt::LeftDockWidgetArea, dockPartie);


    // Connexion
    connect(m_partiesManagerWidget, &PartiesManagerWidget::partieSelectionnee, this, &MainWindow::afficherPartie);
    connect(this, &MainWindow::partieAffichee, widgetPartie, &WidgetPartie::afficherPartie);



    // Création de joueurs
    Glouton1Factory fabrique;

    for (int iJoueur=0; iJoueur<4; iJoueur++) {
        Joueur *joueur = fabrique.creerJoueur();
        m_joueursManager->addJoueur(joueur);
    }

    m_joueursManagerWidget->actualiser();


    // Création de parties
    for (int iPartie=0; iPartie<10; iPartie++) {
        std::vector<Joueur*> joueurs;

        for (int iJoueur=0; iJoueur<iPartie%3+2; iJoueur++) {
            joueurs.push_back( m_joueursManager->getJoueur(iJoueur) );
        }

        SituationJeu situationDepart (joueurs.size());

        for (unsigned int iJoueur=0; iJoueur<joueurs.size(); iJoueur++) {
            situationDepart.setPositionJoueur(iJoueur, rand()%(SituationJeu::NB_CELLULES));
        }

        Partie* partie = SimulateurPartie::simulerPartie(situationDepart, joueurs);
        m_partiesManager->addPartie(partie);

        for (unsigned int iJoueur=0; iJoueur<joueurs.size(); iJoueur++) {
            delete joueurs[iJoueur];
        }
    }


    // Création de parties à la demande
    WJouerPartie *wJouerPartie = new WJouerPartie (m_joueursManager, m_partiesManager);

    QDockWidget *dockJouerPartie = new QDockWidget("Jouer une partie", this);
    dockJouerPartie->setWidget(wJouerPartie);
    addDockWidget(Qt::RightDockWidgetArea, dockJouerPartie);
}

MainWindow::~MainWindow ()
{

}


void MainWindow::afficherPartie (const int idPartie)
{
    Partie *partie = m_partiesManager->getPartie(idPartie);

    emit partieAffichee(partie);
}
