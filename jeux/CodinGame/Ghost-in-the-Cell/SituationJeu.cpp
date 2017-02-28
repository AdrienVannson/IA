#include "SituationJeu.h"


SituationJeu::SituationJeu (const int nbJoueurs) :
    m_nbToursEcoules (0),
    m_idVainqueur(-1)
{
    for (int iJoueur=0; iJoueur<nbJoueurs; iJoueur++) {
        m_nbBombesRestantes.push_back(2);
    }
}


/*
 * Nombre de tours écoulés
 */

int SituationJeu::nbToursEcoules () const
{
    return m_nbToursEcoules;
}

void SituationJeu::incrementerNbToursEcoules ()
{
    m_nbToursEcoules++;
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

int SituationJeu::distance (const int usineA, const int usineB) const
{
    return m_distances[usineA][usineB];
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

void SituationJeu::addTroupe (const Troupe &nouvelleTroupe)
{
    m_troupes.push_back(nouvelleTroupe);
}


/*
 * Bombes restantes
 */

int SituationJeu::nbBombesRestantes (const int idJoueur) const
{
    return m_nbBombesRestantes[idJoueur];
}

void SituationJeu::utiliserBombe (const int idJoueur)
{
    m_nbBombesRestantes[idJoueur]--;
}


/*
 * Actions
 */

const std::vector<Action>* SituationJeu::actions () const
{
    return &m_actions;
}

void SituationJeu::addAction (const Action &nouvelleAction)
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
