#include "WJouerPartie.h"

WJouerPartie::WJouerPartie (QWidget *parent) :
    QWidget (parent)
{
    QVBoxLayout *layout = new QVBoxLayout;

    m_saisieID1 = new QLineEdit ("0");
    layout->addWidget(m_saisieID1);

    m_saisieID2 = new QLineEdit ("0");
    layout->addWidget(m_saisieID2);

    QPushButton *bouttonValidation = new QPushButton ("Jouer la partie");
    connect(bouttonValidation, &QPushButton::clicked, this, &WJouerPartie::simulerPartie);
    layout->addWidget(bouttonValidation);

    setLayout(layout);
}

void WJouerPartie::simulerPartie ()
{
    /*std::vector<Joueur*> joueurs;
    joueurs.push_back( m_joueursManager->getJoueur(m_saisieID1->text().toInt()) );
    joueurs.push_back( m_joueursManager->getJoueur(m_saisieID2->text().toInt()) );

    Partie *partie = SimulateurPartie::simulerPartie(SituationJeu(2), joueurs);
    m_partiesManager->addPartie(partie);

    delete joueurs[0], joueurs[1];*/
}
