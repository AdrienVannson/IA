#include "WAbstractGame.hpp"

WAbstractGame::WAbstractGame (QWidget *parent) :
    QWidget (parent),
    m_iTourActuel (0)
{
    // Timer
    m_timer = new QTimer(this);
    m_timer->setInterval(100);
    connect(m_timer, &QTimer::timeout, this, &WAbstractGame::tourSuivant);

    EventsManager::getInstance()->add(this);
}


void WAbstractGame::showGame (const std::shared_ptr<const DescribedGame> &partie)
{
    m_partie = *partie;
    m_iTourActuel = 0;
    afficherTourActuel();

    m_timer->start();
    updateGeometry();
}

void WAbstractGame::tourSuivant ()
{
    m_iTourActuel = (m_iTourActuel+1) % m_partie.tours()->size();
    afficherTourActuel();
}
