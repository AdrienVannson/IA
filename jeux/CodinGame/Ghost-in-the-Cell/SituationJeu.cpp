#include "SituationJeu.h"


SituationJeu::SituationJeu (const int nbJoueurs) :
    m_nbToursEcoules (0),
    m_idVainqueur(-1)
{
    for (int iJoueur=0; iJoueur<nbJoueurs; iJoueur++) {
        m_nbBombesRestantes.push_back(2);
    }
}


void SituationJeu::initialiser ()
{
    const int iPlateau = rand() % 2; // Tirage au sort du plateau à utiliser

    std::vector< std::vector<int> > distances;

    if (iPlateau == 0) {
        m_usines.push_back( Usine(0, 0, -1, 0) );

        m_usines.push_back( Usine(16, 1, 0, 0) );
        m_usines.push_back( Usine(16, 1, 1, 0) );

        m_usines.push_back( Usine(0, 0, -1, 0) );
        m_usines.push_back( Usine(0, 0, -1, 0) );

        m_usines.push_back( Usine(5, 1, -1, 0) );
        m_usines.push_back( Usine(5, 1, -1, 0) );

        m_usines.push_back( Usine(0, 0, -1, 0) );
        m_usines.push_back( Usine(0, 0, -1, 0) );


        distances = {{
            {0, 1, 1, 4, 4, 2, 2, 3, 3},
            {1, 0, 4, 4, 5, 4, 2, 2, 5},
            {1, 4, 0, 5, 4, 2, 4, 5, 2},
            {4, 4, 5, 0, 9, 1, 7, 1, 8},
            {4, 5, 4, 9, 0, 7, 1, 8, 1},
            {2, 4, 2, 1, 7, 0, 6, 3, 6},
            {2, 2, 4, 7, 1, 6, 0, 6, 3},
            {3, 2, 5, 1, 8, 3, 6, 0, 7},
            {3, 5, 2, 8, 1, 6, 3, 7, 0}
        }};
    }
    else if (iPlateau == 1) {
        m_usines.push_back( Usine(0, 0, -1, 0) );

        m_usines.push_back( Usine(29, 2, 0, 0) );
        m_usines.push_back( Usine(29, 2, 1, 0) );

        m_usines.push_back( Usine(3, 3, -1, 0) );
        m_usines.push_back( Usine(3, 3, -1, 0) );

        m_usines.push_back( Usine(0, 3, -1, 0) );
        m_usines.push_back( Usine(0, 3, -1, 0) );

        m_usines.push_back( Usine(5, 2, -1, 0) );
        m_usines.push_back( Usine(5, 2, -1, 0) );

        m_usines.push_back( Usine(3, 1, -1, 0) );
        m_usines.push_back( Usine(3, 1, -1, 0) );


        distances = {{
            { 0, 3, 3, 4, 4, 7, 7, 8, 8, 7, 7 },
            { 3, 0, 7, 2, 8, 3, 11, 4, 12, 4, 10 },
            { 3, 7, 0, 8, 2, 11, 3, 12, 4, 10, 4 },
            { 4, 2, 8, 0, 10, 2, 12, 4, 13, 1, 13 },
            { 4, 8, 2, 10, 0, 12, 2, 13, 4, 13, 1 },
            { 7, 3, 11, 2, 12, 0, 15, 1, 16, 2, 14 },
            { 7, 11, 3, 12, 2, 15, 0, 16, 1, 14, 2 },
            { 8, 4, 12, 4, 13, 1, 16, 0, 17, 4, 15 },
            { 8, 12, 4, 13, 4, 16, 1, 17, 0, 15, 4 },
            { 7, 4, 10, 1, 13, 2, 14, 4, 15, 0, 15 },
            { 7, 10, 4, 13, 1, 14, 2, 15, 4, 15, 0 }
        }};
    }

    m_distances = distances;
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
