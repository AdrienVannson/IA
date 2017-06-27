#include "AbstractGameSituation.hpp"

AbstractGameSituation::AbstractGameSituation (const int nbJoueurs) :
    m_iPlayer (0),
    m_nbJoueurs (nbJoueurs),
    m_estFini (false)
{
    fill(m_scores.begin(), m_scores.end(), 0);
}



/*
 * Nombre de joueurs
 */

int AbstractGameSituation::nbJoueurs () const
{
    return m_nbJoueurs;
}



/*
 * Joueur devant jouer le coup suivant
 */

int AbstractGameSituation::iPlayer () const
{
    return m_iPlayer;
}

void AbstractGameSituation::setIPlayer (const int iPlayer)
{
    m_iPlayer = iPlayer;
}



/*
 * Fin de la partie
 */

bool AbstractGameSituation::estFini () const
{
    return m_estFini;
}

int AbstractGameSituation::idVainqueur () const
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
