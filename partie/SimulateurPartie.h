/*
 * Simule une partie complète entre deux joueurs
 */

#ifndef SIMULATEURPARTIE_H
#define SIMULATEURPARTIE_H

#include <memory>
#include <vector>

#include "Joueur/Player.hpp"
#include "Game.hpp"
#include "Referee.hpp"
#include "InformationsTourJoueurFactory.h"


class SimulateurPartie
{

public:

    SimulateurPartie ();

    static Game* simulerPartie (const GameSituation &sitDepart, std::vector< std::shared_ptr<Player> > &joueurs);

};

#endif // SIMULATEURPARTIE_H
