#include "SituationJeu.h"


SituationJeu::SituationJeu (const int nbJoueurs) :
    m_idVainqueur(-1)
{

}


/*
 * Usines
 */

// Usines
std::vector<SituationJeu::Usine>* SituationJeu::usines ()
{
    return &m_usines;
}

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
 * Troupes
 */

const std::vector<SituationJeu::Troupe>* SituationJeu::troupes () const
{
    return &m_troupes;
}

std::vector<SituationJeu::Troupe>* SituationJeu::troupes ()
{
    return &m_troupes;
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


/*
 * Fin de la partie
 */

bool SituationJeu::estFini () const
{
    return m_idVainqueur != -1;
}


int SituationJeu::idVainqueur () const
{
    return m_idVainqueur;
}


void SituationJeu::setIdVainqueur (const int nouvelIdVainqueur)
{
    m_idVainqueur = nouvelIdVainqueur;
}

