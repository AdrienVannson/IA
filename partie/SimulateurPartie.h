/*
 * Simule une partie complète entre deux joueurs
 */

#ifndef SIMULATEURPARTIE_H
#define SIMULATEURPARTIE_H

#include <vector>

#include "Joueur/Joueur.h"
#include "Partie.h"
#include "Simulateur.h"
#include "InformationsTourJoueurFactory.h"


class SimulateurPartie
{

public:

    SimulateurPartie ();

    static Partie* simulerPartie (const SituationJeu &sitDepart, std::vector<Joueur*> &joueurs);

};

#endif // SIMULATEURPARTIE_H
