/*
 * Permet de simuler les parties d'un jeu
 */

#ifndef REFEREE_HPP
#define REFEREE_HPP

#include <algorithm>
#include <stack>
#include <vector>

#include "Action.hpp"
#include "partie/Game.hpp"
#include "GameSituation.hpp"


class Referee
{

public:

    Referee ();

    static GameSituation simulerAction (GameSituation situation, const Action &actionAJouer);



private:

    static const int NB_DEPLACEMENTS = 4;
    static int DELTAS_DEPLACEMENTS[NB_DEPLACEMENTS];


};

#endif // REFEREE_HPP
