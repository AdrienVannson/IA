#include "MainWindow.hpp"
#include "initialiser.hpp"

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

    WPartie *widgetPartie = new WPartie;
    m_ongletsParties->addTab(widgetPartie, "Partie");

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


void MainWindow::addDock (QWidget *widget, const QString &nom)
{
    QDockWidget *dock = new QDockWidget(nom, this);
    dock->setWidget(widget);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

void MainWindow::afficherAPropos ()
{
    QMessageBox fenetreAPropos;
    fenetreAPropos.setText("IA\n\nDéveloppement : VANNSON Adrien");
    fenetreAPropos.setWindowTitle("À propos");
    fenetreAPropos.exec();
}

void MainWindow::fermerOnglerPartie (int index)
{
    delete m_ongletsParties->widget(index);
}

void MainWindow::updateNbSimulations ()
{
    m_wNbSimulations->setText("Simulations en attente : " + QString::number(m_gameRunner->nbPendingGames()));
}
