#include "WApercuJoueur.hpp"

WApercuJoueur::WApercuJoueur (QWidget *parent) :
    QWidget (parent)
{
    QVBoxLayout *layout = new QVBoxLayout;

    m_bouton = new QPushButton ("...", this);
    layout->addWidget(m_bouton);

    setLayout(layout);
}

void WApercuJoueur::WApercuJoueur::setObject (const std::shared_ptr<const std::pair< std::function<Joueur*()>, QString> > &joueur)
{
    m_joueur = joueur;
    m_bouton->setText(joueur->second);
}
