#include "SituationJeuGenerale.h"

SituationJeuGenerale::SituationJeuGenerale (const int nbJoueurs) :
    m_nbJoueurs (nbJoueurs),
    m_idVainqueur (-1)
{

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


/*
 * Nombre de joueurs
 */

int SituationJeuGenerale::nbJoueurs () const
{
    return m_nbJoueurs;
}
