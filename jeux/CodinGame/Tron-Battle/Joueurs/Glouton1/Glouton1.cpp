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

    if (informations.m_joueurs[informations.m_idJoueur].second.second == 0) {
        action.setDirection(Action::BAS);
    }

    return action;
}
