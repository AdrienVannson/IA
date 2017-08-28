#include "SituationJeuAbstraite.hpp"

SituationJeuAbstraite::SituationJeuAbstraite () :
    m_iPlayer (0)
{
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
