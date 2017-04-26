#include "PartiesManager.h"

PartiesManager::PartiesManager ()
{

}


// Parties
const std::vector<Partie*>* PartiesManager::parties () const
{
    return &m_parties;
}

Partie* PartiesManager::getPartie (const int idPartie)
{
    return new Partie (*m_parties[idPartie]);
}

void PartiesManager::addPartie (Partie *nouvellePartie)
{
    m_parties.push_back(nouvellePartie);
    emit updated ();
}
