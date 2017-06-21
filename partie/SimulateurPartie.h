/*
 * Simule une partie complète entre deux joueurs
 */

#ifndef SIMULATEURPARTIE_H
#define SIMULATEURPARTIE_H

#include <memory>
#include <vector>

#include "Joueur/Player.hpp"
#include "Partie.h"
#include "Simulateur.h"
#include "InformationsTourJoueurFactory.h"


class SimulateurPartie
{

public:

    SimulateurPartie ();

    static Partie* simulerPartie (const GameSituation &sitDepart, std::vector< std::shared_ptr<Player> > &joueurs);

};

#endif // SIMULATEURPARTIE_H
