#include "SituationJeuGenerale.h"

SituationJeuGenerale::SituationJeuGenerale (const int nbJoueurs) :
    m_iPlayer (0),
    m_nbJoueurs (nbJoueurs),
    m_idVainqueur (-1)
{

}



/*
 * Nombre de joueurs
 */

int SituationJeuGenerale::nbJoueurs () const
{
    return m_nbJoueurs;
}



/*
 * Joueur devant jouer le coup suivant
 */

int SituationJeuGenerale::iPlayer () const
{
    return m_iPlayer;
}

void SituationJeuGenerale::setIPlayer (const int iPlayer)
{
    m_iPlayer = iPlayer;
}



/*
 * Fin de la partie
 */

bool SituationJeuGenerale::estFini () const
{
    return m_idVainqueur != -1;
}

int SituationJeuGenerale::idVainqueur () const
{
    return m_idVainqueur;
}

void SituationJeuGenerale::setIdVainqueur (const int idVainqueur)
{
    m_idVainqueur = idVainqueur;
}
