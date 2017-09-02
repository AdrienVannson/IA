#ifndef SIMULERPARTIE_HPP
#define SIMULERPARTIE_HPP

#include <memory>
#include <vector>

#include "Joueur/Joueur.hpp"
#include "Partie.hpp"
#include "Arbitre.hpp"
#include "InfosFactory.hpp"


std::shared_ptr<Partie> simulerPartie (const SituationJeu &sitDepart, std::vector< std::shared_ptr<Joueur> > &joueurs);


#endif // SIMULERPARTIE_HPP
