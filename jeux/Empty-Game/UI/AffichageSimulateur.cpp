#include "AffichageSimulateur.hpp"

AffichageSimulateur::AffichageSimulateur (QWidget *parent) :
    QGraphicsView(parent)
{
    m_scene = new SceneSimulateur ();

    setScene(m_scene);
}

void AffichageSimulateur::afficherPartie (const Partie &partie)
{
    m_scene->afficherPartie(partie);
}
