#include "SituationJeu.h"


SituationJeu::SituationJeu (const int nbJoueurs)
{

}


/*
 * Usines
 */

// Usines
const std::vector<SituationJeu::Usine>* SituationJeu::usines () const
{
    return &m_usines;
}

void SituationJeu::setUsines (const std::vector<Usine> &nouvellesUsines)
{
    m_usines = nouvellesUsines;
}

// Distances entre les usines
const std::vector< std::vector<int> >* SituationJeu::distances () const
{
    return &m_distances;
}

void SituationJeu::setDistances (const std::vector< std::vector<int> > nouvellesDistances)
{
    m_distances = nouvellesDistances;
}


/*
 * Actions
 */

const std::vector<Action>* SituationJeu::actions () const
{
    return &m_actions;
}

void SituationJeu::ajouterAction (const Action &nouvelleAction)
{
    m_actions.push_back(nouvelleAction);
}

void SituationJeu::supprimerLesActions ()
{
    m_actions.clear();
}
