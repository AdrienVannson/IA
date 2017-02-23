/*
 * Ce fichier est inclut automatiquement
 */

#include "Action.h"


Action::Action() :
    m_idJoueur (-1),
    m_direction(GAUCHE)
{

}


// Direction
Direction Action::direction () const
{
    return m_direction;
}

void Action::setDirection (const Direction nouvelleDirection)
{
    m_direction = nouvelleDirection;
}
