#include "Action.h"


// ID du joueur
int Action::idJoueur () const
{
    return m_idJoueur;
}

void Action::setIdJoueur (const int nouvelIdJoueur)
{
    m_idJoueur = nouvelIdJoueur;
}


#include xstr(jeux/JEU/Action.cpp)