/*
 * Ce fichier est inclut automatiquement
 */

#include "partie/Action.h"


Action::Action() :
    m_idJoueur (-1),
    m_direction(GAUCHE)
{

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
