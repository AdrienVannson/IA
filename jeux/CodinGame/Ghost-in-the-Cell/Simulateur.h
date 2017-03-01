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

    // Fonctions de jeu
    static void avancerTroupes ();
    static void executerAction (const Action &action);
    static void produireUnites ();
    static void combattre ();
    static void exploserBombes ();
    static void verifierFin ();



    // Situation
    static SituationJeu m_situation;


};

#endif // SIMULATEUR_H
