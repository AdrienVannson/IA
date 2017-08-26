#include "SituationJeuAbstraite.hpp"

SituationJeuAbstraite::SituationJeuAbstraite (const int nbJoueurs) :
    m_iPlayer (0),
    m_estFini (false)
{
    m_scores.resize(nbJoueurs);
    std::fill(m_scores.begin(), m_scores.end(), 0);
}


int SituationJeuAbstraite::nbJoueurs () const
{
    return m_scores.size();
}



/*
 * Joueur devant jouer le coup suivant
 */

int SituationJeuAbstraite::iPlayer () const
{
    return m_iPlayer;
}

void SituationJeuAbstraite::setIPlayer (const int iPlayer)
{
    m_iPlayer = iPlayer;
}



/*
 * Fin de la partie
 */

bool SituationJeuAbstraite::estFini () const
{
    return m_estFini;
}

int SituationJeuAbstraite::idVainqueur () const
{
    int iJoueurMax = -1;
    int meilleurScore = std::numeric_limits<int>::min();

    for (unsigned int iJoueur=0; iJoueur<m_scores.size(); iJoueur++) {
        if (m_scores[iJoueur] > meilleurScore) {
            meilleurScore = m_scores[iJoueur];
            iJoueurMax = iJoueur;
        }
    }

    return iJoueurMax;
}
