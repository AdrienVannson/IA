#include "SceneSimulateur.hpp"

SceneSimulateur::SceneSimulateur () :
    m_iTour(0)
{
    setBackgroundBrush(QBrush(QColor(200, 200, 200)));

    m_affichageNbTours = new QGraphicsSimpleTextItem;
    m_affichageNbTours->setPos( QPoint(0, 0) );

    QFont police("Times", 500, QFont::Bold);
    m_affichageNbTours->setFont(police);

    addItem(m_affichageNbTours);

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &SceneSimulateur::tourSuivant);
}

void SceneSimulateur::afficherPartie (const Partie &partie)
{
    m_iTour = -1; // Passera à 0 lors de l'incrémentation au début du tour
    m_partie = partie;
}

void SceneSimulateur::tourSuivant ()
{
    m_iTour = (m_iTour+1) % m_partie.m_situationsJeu.size();
    m_affichageNbTours->setText( QString::number(m_iTour) );
}
