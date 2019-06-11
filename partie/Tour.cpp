#include "Tour.hpp"

Tour::Tour (const SituationJeu &situationDepart)
{
    m_situationJeu = situationDepart;
}


// Situation du jeu
const SituationJeu& Tour::situationJeu () const
{
    return m_situationJeu;
}

void Tour::setSituationJeu (const SituationJeu &nouvelleSituationJeu)
{
    m_situationJeu = nouvelleSituationJeu;
}

// Action
const Action& Tour::action () const
{
    return m_action;
}

void Tour::setAction (const Action &nouvelleAction)
{
    m_action = nouvelleAction;
}
