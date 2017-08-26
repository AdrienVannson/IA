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

        QAction *actionAddGameDock = new QAction("Partie", this);
        connect(actionAddGameDock, &QAction::triggered, this, &MainWindow::addGameDock);
        menuAffichage->addAction(actionAddGameDock);

        QAction *actionAddGameRunnerDock = new QAction("Parties en attente", this);
        connect(actionAddGameRunnerDock, &QAction::triggered, this, &MainWindow::addGameRunnerDock);
        menuAffichage->addAction(actionAddGameRunnerDock);

        QAction *actionAddBatchRunnerDock = new QAction("Batch Run", this);
        connect(actionAddBatchRunnerDock, &QAction::triggered, this, &MainWindow::addBatchRunnerDock);
        menuAffichage->addAction(actionAddBatchRunnerDock);


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
    connect(m_wPartiesManager, &WManager<PartieDecrite, WApercuPartie>::widgetCreated, this, &MainWindow::registerGameOverview);

    QDockWidget *dockParties = new QDockWidget("Parties", this);
    dockParties->setWidget(m_wPartiesManager);
    addDockWidget(Qt::RightDockWidgetArea, dockParties);


    // Affichage des joueurs
    m_wJoueursManager = new WManager<Joueur, WApercuJoueur>;
    m_wJoueursManager->setManager(&m_joueursManager);

    QDockWidget *dockJoueurs = new QDockWidget("Joueurs", this);
    dockJoueurs->setWidget(m_wJoueursManager);
    addDockWidget(Qt::RightDockWidgetArea, dockJoueurs);


    // Création de parties
    connect(&m_gameRunner, &GameRunner::gameRunned, this, &MainWindow::addGame);


    // Création des docks
    addGameDock();
    addGameRunnerDock();
    addBatchRunnerDock();

    // Création de parties à la demande
    /*WJouerPartie *wJouerPartie = new WJouerPartie (m_joueursManager, m_partiesManager);

    QDockWidget *dockJouerPartie = new QDockWidget("Jouer une partie", this);
    dockJouerPartie->setWidget(wJouerPartie);
    addDockWidget(Qt::RightDockWidgetArea, dockJouerPartie);*/


    // Initialisation
    initialiser (this);

    m_wJoueursManager->actualiser();
    m_wPartiesManager->actualiser();
}

MainWindow::~MainWindow ()
{

}

Manager<Joueur>* MainWindow::joueursManager ()
{
    return &m_joueursManager;
}


void MainWindow::addGame (const std::shared_ptr<PartieDecrite> &game)
{
    m_partiesManager.add(game);
    m_wPartiesManager->actualiser();
}

void MainWindow::registerGameOverview (QWidget *apercu)
{
    m_eventsManager.add(dynamic_cast<WApercuPartie*>(apercu));
}


void MainWindow::afficherAPropos ()
{
    QMessageBox fenetreAPropos;
    fenetreAPropos.setText("VIA\n\nLogiciel créé par Adrien VANNSON");
    fenetreAPropos.setWindowTitle("À propos");
    fenetreAPropos.exec();
}

void MainWindow::addGameDock ()
{
    WPartie *widgetPartie = new WPartie;
    m_eventsManager.add(widgetPartie);

    QDockWidget *dockPartie = new QDockWidget("Partie", this);
    dockPartie->setWidget(widgetPartie);
    addDockWidget(Qt::LeftDockWidgetArea, dockPartie);
}

void MainWindow::addGameRunnerDock ()
{
    WGameRunner *gameRunner = new WGameRunner (&m_gameRunner);

    QDockWidget *dock = new QDockWidget("Parties en attente", this);
    dock->setWidget(gameRunner);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

void MainWindow::addBatchRunnerDock ()
{
    WBatchRunner *wBatchRunner = new WBatchRunner;

    for (std::shared_ptr<Joueur> &player : m_joueursManager.getAll()) {
        wBatchRunner->addPlayer(player);
    }

    QDockWidget *dock = new QDockWidget("Batch Run", this);
    dock->setWidget(wBatchRunner);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}
