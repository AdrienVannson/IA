/*
 * Décrit un tour de jeu
 */

#ifndef TOUR_H
#define TOUR_H

#include "Action.h"
#include "GameSituation.hpp"


class Tour
{

public:
    Tour (const GameSituation &situationDepart=GameSituation());

    GameSituation situationJeu () const;
    void setSituationJeu (const GameSituation &nouvelleSituationJeu);

    Action action () const;
    void setAction (const Action &nouvelleAction);


private:

    // Situation du jeu lors du tour
    GameSituation m_situationJeu;

    // Action jouée par le joueur, qui permet d'obtenir la situation du tour suivant
    Action m_action;

};

#endif // TOUR_H
