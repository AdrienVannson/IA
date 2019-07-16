#ifndef SITUATIONJEU_HPP
#define SITUATIONJEU_HPP

#include <vector>

#include "unused.hpp"
#include "Action.hpp"


class SituationJeu
{
public:
    SituationJeu ();

    // Fin de partie
    bool estFini () const;
    std::vector<int> scores () const;

    // Simulation
    void simulerAction (const Action &action);

};

#endif // SITUATIONJEU_HPP
