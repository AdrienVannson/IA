/*
 * Permet de simuler les parties d'un jeu
 */

#ifndef SIMULATEUR_H
#define SIMULATEUR_H

#include <vector>

#include "partie/Partie.h"
#include "SituationJeu.h"


class Simulateur
{

public:

    Simulateur ();

    SituationJeu simulerAction (const SituationJeu &situationDepart, const Action actionAJouer);



private:

    SituationJeu m_situation;


};

#endif // SIMULATEUR_H
