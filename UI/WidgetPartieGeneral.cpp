#include "WidgetPartieGeneral.h"

WidgetPartieGeneral::WidgetPartieGeneral (QWidget *parent) :
    QWidget (parent),
    m_iTourActuel (0)
{
    // Timer
    m_timer = new QTimer(this);
    m_timer->setInterval(50);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(tourSuivant()));
}


void WidgetPartieGeneral::afficherPartie (const Partie *partie)
{
    m_partie = *partie;
    m_iTourActuel = 0;
    afficherTourActuel();

    m_timer->start();
}

void WidgetPartieGeneral::tourSuivant ()
{
    m_iTourActuel = (m_iTourActuel+1) % m_partie.tours()->size();
    afficherTourActuel();
}
