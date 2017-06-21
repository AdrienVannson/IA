/*
 * Permet de simuler les parties d'un jeu
 */

#ifndef SIMULATEUR_H
#define SIMULATEUR_H

#include <algorithm>
#include <stack>
#include <vector>

#include "Action.h"
#include "partie/Partie.h"
#include "GameSituation.hpp"


class Simulateur
{

public:

    Simulateur ();

    static GameSituation simulerAction (GameSituation situation, const Action &actionAJouer);



private:

    static const int NB_DEPLACEMENTS = 4;
    static int DELTAS_DEPLACEMENTS[NB_DEPLACEMENTS];


};

#endif // SIMULATEUR_H
