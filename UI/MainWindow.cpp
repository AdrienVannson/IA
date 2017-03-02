#include "MainWindow.h"

MainWindow::MainWindow (QWidget *parent) :
    QMainWindow(parent)
{
    // Timer d'entrainement
    m_timerEntrainement = new QTimer (this);
    m_timerEntrainement->setInterval(500);
    m_timerEntrainement->setSingleShot(true);

    connect(m_timerEntrainement, SIGNAL(timeout()), this, SLOT(entrainerJoueur()));

    // Ajout d'un joueur naïf
    m_joueurManager.addJoueur(new JoueurNaif);


    showMaximized();

    // Menu
    QMenu *menuFichier = menuBar()->addMenu(tr("Fichier"));

    QAction *actionQuitter = new QAction(tr("Quitter"), this);
    connect(actionQuitter, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

    menuFichier->addAction(actionQuitter);


    // Contenu de la fenêtre
    QPushButton *boutton = new QPushButton("Commencer l'entrainement");
    setCentralWidget(boutton);

    connect(boutton, SIGNAL(clicked(bool)), m_timerEntrainement, SLOT(start()));


    // Création d'une fausse partie (TODEL)
    SituationJeu sitDepart;
    sitDepart.initialiser();

    std::vector<Joueur*> joueurs;
    joueurs.push_back(new JoueurNaif);
    joueurs.push_back(new JoueurNaif);

    Partie *partie = SimulateurPartie::simulerPartie(sitDepart, joueurs);

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


void MainWindow::entrainerJoueur ()
{
    JoueurRegression *joueur = new JoueurRegression;
    joueur->entrainer(&m_joueurManager);

    qDebug() << m_joueurManager.getRatioVictoire(joueur, 100);
    m_joueurManager.addJoueur(joueur);

    m_timerEntrainement->start();
}
