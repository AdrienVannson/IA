#include "WidgetPartie.h"

WidgetPartie::WidgetPartie(QWidget *parent) :
    QWidget (parent),
    m_iTourActuel (0)
{
    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(tourSuivant()));
}

/*QSize WidgetPartie::minimumSizeHint() const
{
    return QSize();
}*/


void WidgetPartie::afficherPartie (const Partie *partie)
{
    m_partie = partie;
    m_iTourActuel = 0;
    afficherTourActuel();

    m_timer->start();
}

void WidgetPartie::tourSuivant ()
{
    m_iTourActuel = (m_iTourActuel+1) % m_partie->tours()->size();
    afficherTourActuel();
}


void WidgetPartie::afficherTourActuel ()
{

}
