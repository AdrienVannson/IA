/*
 * Ce fichier est inclut automatiquement
 */

#include "Action.h"


Action::Action() :
    ActionGenerale (),
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
