/*
 * Ce fichier est inclut automatiquement
 */

#include "Action.h"


Action::Action() :
    m_idJoueur (-1),
    m_direction(GAUCHE)
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


// Direction
Action::Direction Action::direction () const
{
    return m_direction;
}

void Action::setDirection (const Direction nouvelleDirection)
{
    m_direction = nouvelleDirection;
}
