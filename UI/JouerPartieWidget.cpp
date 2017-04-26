#include "JouerPartieWidget.h"

JouerPartieWidget::JouerPartieWidget (JoueursManager *joueurManager, PartiesManager *partiesManager, QWidget *parent) :
    QWidget (parent),
    m_joueursManager (joueurManager),
    m_partiesManager (partiesManager)
{
    QVBoxLayout *layout = new QVBoxLayout;

    m_saisieID1 = new QLineEdit ("0");
    layout->addWidget(m_saisieID1);

    m_saisieID2 = new QLineEdit ("0");
    layout->addWidget(m_saisieID2);

    QPushButton *bouttonValidation = new QPushButton ("Jouer la partie");
    connect(bouttonValidation, &QPushButton::clicked, this, &JouerPartieWidget::simulerPartie);
    layout->addWidget(bouttonValidation);

    setLayout(layout);
}

void JouerPartieWidget::simulerPartie ()
{
    std::vector<Joueur*> joueurs;
    joueurs.push_back( m_joueursManager->getJoueur(m_saisieID1->text().toInt()) );
    joueurs.push_back( m_joueursManager->getJoueur(m_saisieID2->text().toInt()) );

    Partie *partie = SimulateurPartie::simulerPartie(SituationJeu(2), joueurs);
    m_partiesManager->addPartie(partie);

    delete joueurs[0], joueurs[1];
}
