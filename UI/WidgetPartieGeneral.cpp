#include "WidgetPartieGeneral.h"

WidgetPartieGeneral::WidgetPartieGeneral (QWidget *parent) :
    QWidget (parent),
    m_iTourActuel (0)
{
    // Timer
    m_timer = new QTimer(this);
    m_timer->setInterval(100);
    connect(m_timer, &QTimer::timeout, this, &WidgetPartieGeneral::tourSuivant);

    EventsManager::getInstance()->add(this);
}


void WidgetPartieGeneral::showGame (const std::shared_ptr<const DescribedGame> &partie)
{
    m_partie = *partie;
    m_iTourActuel = 0;
    afficherTourActuel();

    m_timer->start();
    updateGeometry();
}

void WidgetPartieGeneral::tourSuivant ()
{
    m_iTourActuel = (m_iTourActuel+1) % m_partie.tours()->size();
    afficherTourActuel();
}
