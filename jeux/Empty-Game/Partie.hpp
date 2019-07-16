#ifndef PARTIE_HPP
#define PARTIE_HPP

#include <vector>

#include "SituationJeu.hpp"


class Partie
{
public:
    Partie ();


// Membres publiques
    std::vector<SituationJeu> m_situationsJeu;
    std::vector<Action> m_actions;

};

#endif // PARTIE_HPP
