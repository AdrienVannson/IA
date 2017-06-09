#include "WApercuJoueur.hpp"

WApercuJoueur::WApercuJoueur (QWidget *parent) :
    QWidget (parent),
    m_joueur (0)
{
    m_bouton = new QPushButton ("Ah...", this);
}

void WApercuJoueur::WApercuJoueur::setObjet (const Joueur *joueur)
{
    m_joueur = joueur;
    m_bouton->setText("Joueur");
}
