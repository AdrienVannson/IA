#include "SituationJeu.h"


SituationJeu::SituationJeu (const int nbJoueurs)
{

}


void SituationJeu::setUsines (const std::vector<Usine> &nouvellesUsines, const std::vector< std::vector<int> > nouvellesDistances)
{
    m_usines = nouvellesUsines;
    m_distances = nouvellesDistances;
}


/*
 * Actions
 */

const std::vector<Action>* SituationJeu::actions () const
{
    return m_actions;
}

void SituationJeu::ajouterAction (const Action &nouvelleAction)
{
    m_actions.push_back(nouvelleAction);
}

void SituationJeu::supprimerLesActions ()
{
    m_actions.clear();
}
