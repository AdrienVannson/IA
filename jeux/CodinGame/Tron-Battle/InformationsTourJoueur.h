/*
 * Informations données à un joueur pour un tour de jeu
 */

#ifndef INFORMATIONSTOURJOUEUR_H
#define INFORMATIONSTOURJOUEUR_H

#include <utility>
#include <vector>

#include "GameSituation.hpp"


class InformationsTourJoueur
{

public:

    InformationsTourJoueur ();

    int m_idJoueur;
    std::vector< std::pair< std::pair<int, int>, std::pair<int, int> > > m_joueurs;


};

#endif // INFORMATIONSTOURJOUEUR_H
