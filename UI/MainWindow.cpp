#include "MainWindow.hpp"

MainWindow::MainWindow (QWidget *parent) :
    QMainWindow(parent)
{
    showMaximized();
    setWindowTitle("VIA");

    // Menu
    QMenu *menuFichier = menuBar()->addMenu("Fichier");

        QAction *actionQuitter = new QAction("Quitter", this);
        connect(actionQuitter, &QAction::triggered, qApp, &QApplication::quit);
        menuFichier->addAction(actionQuitter);


    QMenu *menuAffichage = menuBar()->addMenu("Affichage");

        QAction *actionAddDockGame = new QAction("Partie", this);
        connect(actionAddDockGame, &QAction::triggered, this, &MainWindow::addDockGame);
        menuAffichage->addAction(actionAddDockGame);


    QMenu *menuAide = menuBar()->addMenu("Aide");

        QAction *actionAPropos = new QAction("À propos", this);
        connect(actionAPropos, &QAction::triggered, this, &MainWindow::afficherAPropos);
        menuAide->addAction(actionAPropos);


    // Boutton
    QPushButton *boutton = new QPushButton ("Salut :)");
    setCentralWidget(boutton);



    // Affichage des parties
    m_wPartiesManager = new WManager<PartieDecrite, WApercuPartie>;
    m_wPartiesManager->setManager(&m_partiesManager);

    QDockWidget *dockParties = new QDockWidget("Parties", this);
    dockParties->setWidget(m_wPartiesManager);
    addDockWidget(Qt::RightDockWidgetArea, dockParties);


    // Affichage des joueurs
    m_wJoueursManager = new WManager<Player, WApercuJoueur>;
    m_wJoueursManager->setManager(&m_joueursManager);

    QDockWidget *dockJoueurs = new QDockWidget("Joueurs", this);
    dockJoueurs->setWidget(m_wJoueursManager);
    addDockWidget(Qt::RightDockWidgetArea, dockJoueurs);


    // Création de parties
    m_wGameRunner = new WGameRunner (&m_gameRunner);
    connect(&m_gameRunner, &GameRunner::gameRunned, this, &MainWindow::addGame);


    // Affichage d'une partie
    addDockGame();



    // Création de joueurs
    /*ExternalPlayer *joueur1 = new ExternalPlayer ("/media/adrien/DATA_LINUX/Documents/Projets/IA/IA/players/minmax");
    ExternalPlayer *joueur2 = new ExternalPlayer ("/media/adrien/DATA_LINUX/Documents/Projets/IA/IA/players/MCTS");

    m_joueursManager.add(joueur1);
    m_joueursManager.add(joueur2);*/


    for (int iPlayer=0; iPlayer<5; iPlayer++) {
        ExternalPlayer *player = new ExternalPlayer ("/media/adrien/DATA_LINUX/Documents/CodinGame/Tron-Battle/Tron-IA/prog");
        m_joueursManager.add(player);
    }


    m_wJoueursManager->actualiser();


    // Création de parties
    for (int iPartie=0; iPartie<1; iPartie++) {
        std::vector< std::shared_ptr<Player> > players;

        for (int iPlayer=0; iPlayer<3; iPlayer++) {
            std::shared_ptr<Player> player = m_joueursManager.get(iPlayer);
            players.push_back(player);
        }

        m_gameRunner.runGame(players);
    }


    m_wPartiesManager->actualiser();


    // Création de parties à la demande
    /*WJouerPartie *wJouerPartie = new WJouerPartie (m_joueursManager, m_partiesManager);

    QDockWidget *dockJouerPartie = new QDockWidget("Jouer une partie", this);
    dockJouerPartie->setWidget(wJouerPartie);
    addDockWidget(Qt::RightDockWidgetArea, dockJouerPartie);*/
}

MainWindow::~MainWindow ()
{

}


void MainWindow::addGame (const std::shared_ptr<PartieDecrite> &game)
{
    m_partiesManager.add(game);
    m_wPartiesManager->actualiser();
}


void MainWindow::afficherAPropos ()
{
    QMessageBox fenetreAPropos;
    fenetreAPropos.setText("VIA\n\nLogiciel créé par Adrien VANNSON");
    fenetreAPropos.setWindowTitle("À propos");
    fenetreAPropos.exec();
}

void MainWindow::addDockGame ()
{
    WGame *widgetPartie = new WGame;

    QDockWidget *dockPartie = new QDockWidget("Partie", this);
    dockPartie->setWidget(widgetPartie);
    addDockWidget(Qt::LeftDockWidgetArea, dockPartie);
}
