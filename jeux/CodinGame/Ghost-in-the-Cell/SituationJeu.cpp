#include "SituationJeu.h"


SituationJeu::SituationJeu (const int nbJoueurs)
{

}


void SituationJeu::setUsines (const std::vector<Usine> &nouvellesUsines, const std::vector< std::vector<int> > nouvellesDistances)
{
    m_usines = nouvellesUsines;
    m_distances = nouvellesDistances;
}
