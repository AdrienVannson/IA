#include "MainWindow.hpp"

MainWindow::MainWindow (QWidget *parent) :
    QMainWindow(parent)
{
    showMaximized();
    setWindowTitle("IA");

    // Menu
    QMenu *menuFichier = menuBar()->addMenu("Fichier");

        QAction *actionQuitter = new QAction("Quitter", this);
        connect(actionQuitter, &QAction::triggered, qApp, &QApplication::quit);
        menuFichier->addAction(actionQuitter);


    QMenu *menuAffichage = menuBar()->addMenu("Affichage");

        QAction *actionAddGameDock = new QAction("Partie", this);
        connect(actionAddGameDock, &QAction::triggered, this, &MainWindow::ajouterAffichagePartie);
        menuAffichage->addAction(actionAddGameDock);

        QAction *actionAddBatchRunnerDock = new QAction("Batch Run", this);
        connect(actionAddBatchRunnerDock, &QAction::triggered, this, &MainWindow::addBatchRunnerDock);
        menuAffichage->addAction(actionAddBatchRunnerDock);


    QMenu *menuAide = menuBar()->addMenu("Aide");

        QAction *actionAPropos = new QAction("À propos", this);
        connect(actionAPropos, &QAction::triggered, this, &MainWindow::afficherAPropos);
        menuAide->addAction(actionAPropos);


    // Parties
    m_ongletsParties = new QTabWidget;
    m_ongletsParties->setTabsClosable(true);
    m_ongletsParties->setMovable(true);

    setCentralWidget(m_ongletsParties);
    connect(m_ongletsParties, &QTabWidget::tabCloseRequested, this, &MainWindow::fermerOnglerPartie);


    // Affichage des parties
    m_wPartiesManager = new WManager<Partie, WApercuPartie>;
    m_wPartiesManager->setManager(&m_partiesManager);
    connect(m_wPartiesManager, &WManager<Partie, WApercuPartie>::widgetCreated, this, &MainWindow::registerGameOverview);

    QDockWidget *dockParties = new QDockWidget("Parties", this);
    dockParties->setWidget(m_wPartiesManager);
    addDockWidget(Qt::RightDockWidgetArea, dockParties);


    // Affichage des joueurs
    m_wJoueursManager = new WManager<JoueurFactory, WApercuJoueur>;
    m_wJoueursManager->setManager(&m_joueursManager);

    QDockWidget *dockJoueurs = new QDockWidget("Joueurs", this);
    dockJoueurs->setWidget(m_wJoueursManager);
    addDockWidget(Qt::RightDockWidgetArea, dockJoueurs);


    // Création de parties
    m_gameRunner = new GameRunner (this);
    m_wNbSimulations = new QLabel ();
    statusBar()->addWidget(m_wNbSimulations);
    updateNbSimulations();

    connect(m_gameRunner, &GameRunner::gameRunned, this, &MainWindow::addGame);
    connect(m_gameRunner, &GameRunner::updated, this, &MainWindow::updateNbSimulations);

    // Création des docks
    ajouterAffichagePartie();

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
{}

Manager<JoueurFactory>* MainWindow::joueursManager ()
{
    return &m_joueursManager;
}

Manager<Partie>* MainWindow::partiesManager ()
{
    return &m_partiesManager;
}

GameRunner* MainWindow::gameRunner ()
{
    return m_gameRunner;
}


void MainWindow::addGame (const shared_ptr<Partie> &game)
{
    m_partiesManager.add(game);
    m_wPartiesManager->actualiser();
}

void MainWindow::registerGameOverview (QWidget *apercu)
{
    connect(dynamic_cast<WApercuPartie*>(apercu), &WApercuPartie::show, this, &MainWindow::afficherPartie);
}

void MainWindow::afficherPartie (shared_ptr<const Partie> partie)
{
    if (m_ongletsParties->currentIndex() != -1) {
        dynamic_cast<WAbstractPartie*>(m_ongletsParties->currentWidget())->showGame(partie);
    }
}


void MainWindow::afficherAPropos ()
{
    QMessageBox fenetreAPropos;
    fenetreAPropos.setText("IA\n\nDéveloppement : VANNSON Adrien");
    fenetreAPropos.setWindowTitle("À propos");
    fenetreAPropos.exec();
}

void MainWindow::ajouterAffichagePartie ()
{
    WPartie *widgetPartie = new WPartie;
    m_ongletsParties->addTab(widgetPartie, "Partie");
}

void MainWindow::addBatchRunnerDock ()
{
    vector<shared_ptr<JoueurFactory>> joueurs;
    joueurs.push_back(m_joueursManager.get(0));
    joueurs.push_back(m_joueursManager.get(0));
    joueurs.push_back(m_joueursManager.get(0));

    WBatchRunner *wBatchRunner = new WBatchRunner (m_gameRunner, joueurs);

    QDockWidget *dock = new QDockWidget("Batch Run", this);
    dock->setWidget(wBatchRunner);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

void MainWindow::fermerOnglerPartie (int index)
{
    delete m_ongletsParties->widget(index);
}

void MainWindow::updateNbSimulations ()
{
    m_wNbSimulations->setText("Simulations en attente : " + QString::number(m_gameRunner->nbPendingGames()));
}
