/*
 * Ce fichier est inclut automatiquement
 */

#include "Action.h"


Action::Action() :
    m_idJoueur (-1)
{

}


// ID du joueur
int Action::idJoueur () const
{
    return m_idJoueur;
}

void Action::setIdJoueur (const int nouvelIdJoueur)
{
    m_idJoueur = nouvelIdJoueur;
}



/*
 * Type
 */

Action::Type Action::type () const
{
    return m_type;
}

void Action::setType (const Type nouveauType)
{
    m_type = nouveauType;
}


/*
 * Informations
 */

int Action::information (const int iInformation) const
{
    return m_informations[iInformation];
}

void Action::setInformation (const int nouvelleValeur, const int iInformation)
{
    m_informations[iInformation] = nouvelleValeur;
}
