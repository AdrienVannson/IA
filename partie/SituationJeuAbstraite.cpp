#include "SituationJeuAbstraite.hpp"

SituationJeuAbstraite::SituationJeuAbstraite (const int nbJoueurs) :
    m_iPlayer (0),
    m_nbJoueurs (nbJoueurs)
{
}


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
