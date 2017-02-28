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

    SituationJeu simulerAction (const SituationJeu &situationDepart, const Action actionAJouer);



private:

    // Fonctions de jeu
    void avancerTroupes ();
    void executerAction (const Action &action);
    void produireUnites ();
    void combattre ();
    void exploserBombes ();
    void verifierFin();



    // Situation
    SituationJeu m_situation;


};

#endif // SIMULATEUR_H
