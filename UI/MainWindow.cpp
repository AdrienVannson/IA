#include "MainWindow.h"

MainWindow::MainWindow (QWidget *parent) :
    QMainWindow(parent)
{
    showMaximized();
    setWindowTitle("VIA");

    m_partiesManager = new PartiesManager;

    // Menu
    QMenu *menuFichier = menuBar()->addMenu("Fichier");

    QAction *actionQuitter = new QAction("Quitter", this);
    connect(actionQuitter, &QAction::triggered, qApp, &QApplication::quit);
    menuFichier->addAction(actionQuitter);


    QMenu *menuAide = menuBar()->addMenu("Aide");

    QAction *actionAPropos = new QAction("À propos", this);
    connect(actionAPropos, &QAction::triggered, this, &MainWindow::afficherAPropos);
    menuAide->addAction(actionAPropos);


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
    m_wJoueursManager = new WManager<Joueur, WApercuJoueur>;
    m_wJoueursManager->setManager(&m_joueursManager);

    QDockWidget *dockJoueurs = new QDockWidget("Joueurs", this);
    dockJoueurs->setWidget(m_wJoueursManager);
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
        m_joueursManager.add( fabrique.creerJoueur() );
    }

    m_wJoueursManager->actualiser();


    // Création de parties
    for (int iPartie=0; iPartie<10; iPartie++) {
        std::vector<Joueur*> joueurs;

        for (int iJoueur=0; iJoueur<iPartie%3+2; iJoueur++) {
            Joueur *joueur = (m_joueursManager.get(iJoueur))->clone();
            joueurs.push_back(joueur);
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
    /*WJouerPartie *wJouerPartie = new WJouerPartie (m_joueursManager, m_partiesManager);

    QDockWidget *dockJouerPartie = new QDockWidget("Jouer une partie", this);
    dockJouerPartie->setWidget(wJouerPartie);
    addDockWidget(Qt::RightDockWidgetArea, dockJouerPartie);*/
}

MainWindow::~MainWindow ()
{

}


void MainWindow::afficherAPropos ()
{
    QMessageBox fenetreAPropos;
    fenetreAPropos.setText("VIA\n\nLogiciel créé par Adrien VANNSON");
    fenetreAPropos.setWindowTitle("À propos");
    fenetreAPropos.exec();
}

void MainWindow::afficherPartie (const int idPartie)
{
    Partie *partie = m_partiesManager->getPartie(idPartie);

    emit partieAffichee(partie);
}
