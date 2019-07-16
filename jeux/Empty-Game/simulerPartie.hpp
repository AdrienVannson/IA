#ifndef SIMULERPARTIE_HPP
#define SIMULERPARTIE_HPP

#include <memory>
#include <vector>

#include "Joueur.hpp"
#include "Partie.hpp"


std::shared_ptr<Partie> simulerPartie (std::vector<std::shared_ptr<Joueur>> &joueurs);


#endif // SIMULERPARTIE_HPP
