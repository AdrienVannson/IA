#ifndef SIMULATEURPARTIE_H
#define SIMULATEURPARTIE_H

#include <memory>
#include <vector>

#include "Joueur/Joueur.hpp"
#include "Partie.hpp"
#include "Arbitre.hpp"
#include "InfosFactory.hpp"


class SimulateurPartie
{

public:

    SimulateurPartie ();

    static Partie* simulerPartie (const SituationJeu &sitDepart, std::vector< std::shared_ptr<Joueur> > &joueurs);

};

#endif // SIMULATEURPARTIE_H
