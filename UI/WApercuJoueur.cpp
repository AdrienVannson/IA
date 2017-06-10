#include "WApercuJoueur.hpp"

WApercuJoueur::WApercuJoueur (QWidget *parent) :
    QWidget (parent),
    m_joueur (0)
{
    QVBoxLayout *layout = new QVBoxLayout;

    m_bouton = new QPushButton ("Ah...", this);
    layout->addWidget(m_bouton);

    setLayout(layout);
}

void WApercuJoueur::WApercuJoueur::setObjet (const Joueur *joueur)
{
    m_joueur = joueur;
    m_bouton->setText("Joueur");
}
