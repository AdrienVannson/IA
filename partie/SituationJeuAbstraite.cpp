#include "SituationJeuAbstraite.hpp"

SituationJeuAbstraite::SituationJeuAbstraite (const int nbJoueurs) :
    m_iPlayer (0),
    m_nbJoueurs (nbJoueurs),
    m_estFini (false)
{
    std::fill(m_scores.begin(), m_scores.end(), 0);
}



/*
 * Nombre de joueurs
 */

int SituationJeuAbstraite::nbJoueurs () const
{
    return m_nbJoueurs;
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

    for (int iJoueur=0; iJoueur<m_nbJoueurs; iJoueur++) {
        if (m_scores[iJoueur] > meilleurScore) {
            meilleurScore = m_scores[iJoueur];
            iJoueurMax = iJoueur;
        }
    }

    return iJoueurMax;
}
