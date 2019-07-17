#include "WAbstractPartie.hpp"

using namespace std;

WAbstractPartie::WAbstractPartie (QWidget *parent) :
    QWidget (parent),
    m_tourActuel (0)
{
    // Timer
    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    connect(m_timer, &QTimer::timeout, this, &WAbstractPartie::tourSuivant);
}


void WAbstractPartie::showGame (const shared_ptr<const Partie> &partie)
{
    m_partie = partie;
    m_tourActuel = 0;

    initialiserPartie();
    afficherTourActuel();

    m_timer->start();
}

void WAbstractPartie::tourSuivant ()
{
    m_tourActuel = (m_tourActuel+1) % m_partie->m_situationsJeu.size();
    afficherTourActuel();
}
