#include "SituationJeu.hpp"

using namespace std;

SituationJeu::SituationJeu ()
{}


/*
 * Fin de partie
 */

bool SituationJeu::estFini () const
{
    return false;
}

vector<int> SituationJeu::scores () const
{
    return {0, 0};
}


/*
 * Simulation
 */

void SituationJeu::simulerAction (const Action &action)
{}
