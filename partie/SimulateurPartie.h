/*
 * Simule une partie complète entre deux joueurs
 */

#ifndef SIMULATEURPARTIE_H
#define SIMULATEURPARTIE_H

#include <memory>
#include <vector>

#include "Joueur/Joueur.hpp"
#include "Game.hpp"
#include "Arbitre.hpp"
#include "InformationsTourJoueurFactory.h"


class SimulateurPartie
{

public:

    SimulateurPartie ();

    static Game* simulerPartie (const SituationJeu &sitDepart, std::vector< std::shared_ptr<Joueur> > &joueurs);

};

#endif // SIMULATEURPARTIE_H
