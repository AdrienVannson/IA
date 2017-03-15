/*
 * Permet de simuler les parties d'un jeu
 */

#ifndef SIMULATEUR_H
#define SIMULATEUR_H

#include <algorithm>
#include <stack>
#include <vector>

#include "partie/Partie.h"
#include "SituationJeu.h"


class Simulateur
{

public:

    Simulateur ();

    static SituationJeu simulerAction (const SituationJeu &situationDepart, const Action &actionAJouer);



private:


};

#endif // SIMULATEUR_H
