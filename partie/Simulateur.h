/*
 * Permet de simuler les parties d'un jeu
 */

#ifndef SIMULATEUR_H
#define SIMULATEUR_H

#include <vector>

#include "Partie.h"
#include "SituationJeu.h"


class Simulateur
{

public:
    Simulateur ();

    SituationJeu simulerAction (const SituationJeu &situationDepart, const Action actionAJouer);

};

#endif // SIMULATEUR_H
