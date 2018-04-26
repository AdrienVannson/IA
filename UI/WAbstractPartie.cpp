#include "WAbstractPartie.hpp"

WAbstractPartie::WAbstractPartie (QWidget *parent) :
    QWidget (parent),
    m_iTourActuel (0)
{
    // Timer
    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    connect(m_timer, &QTimer::timeout, this, &WAbstractPartie::tourSuivant);
}


void WAbstractPartie::showGame (const shared_ptr<const Partie> &partie)
{
    m_partie = partie;
    m_iTourActuel = 0;
    afficherTourActuel();

    m_timer->start();
    updateGeometry();

    afficherPartie(partie);
}

void WAbstractPartie::tourSuivant ()
{
    m_iTourActuel = (m_iTourActuel+1) % m_partie->tours().size();
    afficherTourActuel();
}

void WAbstractPartie::afficherPartie (const shared_ptr<const Partie> &partie)
{
    UNUSED(partie);
}
