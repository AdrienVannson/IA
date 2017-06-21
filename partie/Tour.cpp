#include "Tour.h"

Tour::Tour (const GameSituation &situationDepart)
{
    m_situationJeu = situationDepart;
}


// Situation de jeu
GameSituation Tour::situationJeu () const
{
    return m_situationJeu;
}

void Tour::setSituationJeu (const GameSituation &nouvelleSituationJeu)
{
    m_situationJeu = nouvelleSituationJeu;
}

// Action
Action Tour::action () const
{
    return m_action;
}

void Tour::setAction (const Action &nouvelleAction)
{
    m_action = nouvelleAction;
}
