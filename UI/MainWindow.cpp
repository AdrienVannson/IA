#include "MainWindow.h"

MainWindow::MainWindow (QWidget *parent) :
    QMainWindow(parent)
{
    // Ajout d'un joueur naïf
    m_joueurManager.addJoueur(new JoueurNaif);


    showMaximized();

    // Menu
    QMenu *menuFichier = menuBar()->addMenu(tr("Fichier"));

    QAction *actionQuitter = new QAction(tr("Quitter"), this);
    connect(actionQuitter, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

    menuFichier->addAction(actionQuitter);


    // Contenu de la fenêtre
    QPushButton *boutton = new QPushButton("Bienvenue");
    setCentralWidget(boutton);


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
