#include "AbstractGameSituation.hpp"

AbstractGameSituation::AbstractGameSituation (const int nbJoueurs) :
    m_iPlayer (0),
    m_nbJoueurs (nbJoueurs),
    m_idVainqueur (-1)
{

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
    return m_idVainqueur != -1;
}

int AbstractGameSituation::idVainqueur () const
{
    return m_idVainqueur;
}

void AbstractGameSituation::setIdVainqueur (const int idVainqueur)
{
    m_idVainqueur = idVainqueur;
}
