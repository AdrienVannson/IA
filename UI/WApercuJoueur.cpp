#include "WApercuJoueur.hpp"

WApercuJoueur::WApercuJoueur (QWidget *parent) :
    QWidget (parent)
{
    QVBoxLayout *layout = new QVBoxLayout;

    m_bouton = new QPushButton ("Ah...", this);
    layout->addWidget(m_bouton);

    setLayout(layout);
}

void WApercuJoueur::WApercuJoueur::setObject (const std::shared_ptr<const JoueurFactory> &joueur)
{
    m_joueur = joueur;
    m_bouton->setText("Joueur");
}
