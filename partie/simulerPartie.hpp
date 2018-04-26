#ifndef SIMULERPARTIE_HPP
#define SIMULERPARTIE_HPP

#include <memory>
#include <vector>

#include "Joueur/Joueur.hpp"
#include "Partie.hpp"
#include "arbitre.hpp"
#include "InfosFactory.hpp"

using namespace std;


shared_ptr<Partie> simulerPartie (const SituationJeu &sitDepart, vector<shared_ptr<Joueur>> &joueurs);


#endif // SIMULERPARTIE_HPP
