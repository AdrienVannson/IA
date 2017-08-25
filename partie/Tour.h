/*
 * Décrit un tour de jeu
 */

#ifndef TOUR_H
#define TOUR_H

#include "Action.hpp"
#include "SituationJeu.hpp"


class Tour
{

public:
    Tour (const SituationJeu &situationDepart=SituationJeu());

    SituationJeu situationJeu () const;
    void setSituationJeu (const SituationJeu &nouvelleSituationJeu);

    Action action () const;
    void setAction (const Action &nouvelleAction);


private:

    // Situation du jeu lors du tour
    SituationJeu m_situationJeu;

    // Action jouée par le joueur, qui permet d'obtenir la situation du tour suivant
    Action m_action;

};

#endif // TOUR_H
