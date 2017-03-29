#include "Glouton1.h"

Glouton1::Glouton1 ()
{
}

Glouton1::~Glouton1 ()
{
}

Action Glouton1::jouerAction (const InformationsTourJoueur &informations)
{
    Action action;
    action.setDirection(Action::GAUCHE);

    return action;
}
