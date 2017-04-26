#include "ActionGenerale.h"

ActionGenerale::ActionGenerale () :
    m_idJoueur (-1)
{

}


// ID du joueur
int ActionGenerale::idJoueur () const
{
    return m_idJoueur;
}

void ActionGenerale::setIdJoueur (const int nouvelIdJoueur)
{
    m_idJoueur = nouvelIdJoueur;
}
