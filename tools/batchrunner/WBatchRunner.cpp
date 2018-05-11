#include "WBatchRunner.hpp"

CallbackBatchRunner::CallbackBatchRunner (const int iJoueur1, const int iJoueur2) :
    CallbackFinSimulation (),
    m_iJoueur1 (iJoueur1),
    m_iJoueur2 (iJoueur2)
{}

void CallbackBatchRunner::operator() (const shared_ptr<Partie> &partie)
{
    vector<int> scores = partie->dernierTour().situationJeu().scores();

    if (scores[0] > scores[1]) {
        emit victoire(m_iJoueur1, m_iJoueur2);
    }
    if (scores[0] < scores[1]) {
        emit victoire(m_iJoueur2, m_iJoueur1);
    }

    // Égalité, ne rien faire
}


WBatchRunner::WBatchRunner (GameRunner *gameRunner, const vector<shared_ptr<JoueurFactory>> &joueurs, QWidget *parent) :
    QWidget (parent),
    m_gameRunner (gameRunner),
    m_joueurs (joueurs)
{
    m_layout = new QVBoxLayout;
    setLayout(m_layout);

    // Tableau d'affichage des résultats
    m_tableau = new QTableWidget(joueurs.size(), joueurs.size()+1);
    m_layout->addWidget(m_tableau);

    m_tableau->setHorizontalHeaderItem(joueurs.size(), new QTableWidgetItem ("Total"));

    for (int iJoueur1=0; iJoueur1<(int)joueurs.size(); iJoueur1++) {
        m_nbVictoires.push_back(vector<int>());

        for (int iJoueur2=0; iJoueur2<=(int)joueurs.size(); iJoueur2++) {
            m_nbVictoires.back().push_back(0);

            QTableWidgetItem *item = new QTableWidgetItem;

            if (iJoueur1 == iJoueur2) {
                item->setText("-");
            }
            else {
                item->setText("0");
            }

            m_tableau->setItem(iJoueur1, iJoueur2, item);
        }
    }

    m_champNbParties = new QLineEdit;
    m_champNbParties->setPlaceholderText("Nombre de parties");
    m_champNbParties->setValidator( new QIntValidator(this) );
    m_layout->addWidget(m_champNbParties);

    m_bouttonDemarrer = new QPushButton ("Démarrer");
    connect(m_bouttonDemarrer, &QPushButton::clicked, this, &WBatchRunner::lancerParties);
    m_layout->addWidget(m_bouttonDemarrer);
}

void WBatchRunner::lancerParties ()
{
    const int nbParties = m_champNbParties->text().toInt();

    for (int iPartie=0; iPartie<nbParties; iPartie++) {

        for (int iJoueur1=0; iJoueur1<(int)m_joueurs.size(); iJoueur1++) {
            for (int iJoueur2=0; iJoueur2<(int)m_joueurs.size(); iJoueur2++) {
                if (iJoueur1 == iJoueur2) {
                    continue;
                }

                CallbackBatchRunner *callback = new CallbackBatchRunner (iJoueur1, iJoueur2);
                connect(callback, &CallbackBatchRunner::victoire, this, &WBatchRunner::aGagne);

                vector<shared_ptr<Joueur>> joueurs;
                joueurs.push_back(m_joueurs[iJoueur1]->getNewPlayer());
                joueurs.push_back(m_joueurs[iJoueur2]->getNewPlayer());

                m_gameRunner->runGame(joueurs, callback);
            }
        }
    }
}

void WBatchRunner::aGagne (const int iJoueur, const int iAdversaire)
{
    m_nbVictoires[iJoueur][iAdversaire]++;
    m_tableau->item(iJoueur, iAdversaire)->setText(QString::number(m_nbVictoires[iJoueur][iAdversaire]));

    // Mise à jour du nombre total de victoires
    int nbVictoires = 0;
    for (int iAutre=0; iAutre<(int)m_joueurs.size(); iAutre++) {
        nbVictoires += m_nbVictoires[iJoueur][iAutre];
    }

    m_tableau->item(iJoueur, m_joueurs.size())->setText(QString::number(nbVictoires));
}
