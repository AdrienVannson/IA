#include "WPartie.hpp"

WPartie::WPartie (QWidget *parent) :
    WAbstractPartie (parent)
{
    m_vue = new AffichageSimulateur;

    // Layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_vue);
    setLayout(layout);
}

void WPartie::afficherPartie (const std::shared_ptr<const Partie> &partie)
{
    m_vue->afficherPartie(*partie.get());
}
