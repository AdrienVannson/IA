#include "WBatchRunner.hpp"

WBatchRunner::WBatchRunner (MainWindow *mainWindow, QWidget *parent) :
    QWidget (parent),
    m_mainWindow (mainWindow),
    m_nbJoueurs (4)
{
    m_layout = new QVBoxLayout;
    setLayout(m_layout);


    // Layout des joueurs
    QWidget *widgetJoueurs = new QWidget;
    m_layout->addWidget(widgetJoueurs);

    m_layoutJoueurs = new QVBoxLayout;
    widgetJoueurs->setLayout(m_layoutJoueurs);


    // Interface
    m_champNbParties = new QLineEdit;
    m_champNbParties->setPlaceholderText("Nombre de parties");
    m_champNbParties->setValidator( new QIntValidator(this) );
    m_layout->addWidget(m_champNbParties);

    m_bouttonDemarrer = new QPushButton ("Démarrer");
    connect(m_bouttonDemarrer, &QPushButton::clicked, this, &WBatchRunner::lancerParties);
    m_layout->addWidget(m_bouttonDemarrer);

    m_barreProgression = new QProgressBar;
    m_barreProgression->setValue(42);
    m_layout->addWidget(m_barreProgression);

    updateJoueurs();
}


void WBatchRunner::updateJoueurs ()
{
    for (QLineEdit *champ : m_champsJoueurs) {
        delete champ;
    }
    m_champsJoueurs.clear();

    for (int iJoueur=0; iJoueur<m_nbJoueurs; iJoueur++) {
        QLineEdit *champ = new QLineEdit ("-1");
        champ->setValidator( new QIntValidator(this) );

        m_layoutJoueurs->addWidget(champ);

        m_champsJoueurs.push_back(champ);
    }
}

void WBatchRunner::lancerParties ()
{
    const int nbParties = m_champNbParties->text().toInt();

    Manager<JoueurFactory>* joueurManager = m_mainWindow->joueursManager();


    for (int iPartie=0; iPartie<nbParties; iPartie++) {
        std::vector<std::shared_ptr<Joueur>> joueurs;

        for (QLineEdit *champ : m_champsJoueurs) {
            const int valeur = champ->text().toInt();

            if (valeur < 0 || valeur >= (int)joueurManager->size()) {
                continue;
            }

            joueurs.push_back( joueurManager->get(valeur)->getNewPlayer() );
        }

        m_mainWindow->gameRunner()->runGame(joueurs);
    }
}
