/*
 * Ce fichier est inclut automatiquement
 */

#include "Action.h"


Action::Action() :
    m_idJoueur (-1)
{

}


// ID du joueur
int Action::idJoueur () const
{
    return m_idJoueur;
}

void Action::setIdJoueur (const int nouvelIdJoueur)
{
    m_idJoueur = nouvelIdJoueur;
}
