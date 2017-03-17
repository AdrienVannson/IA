#include "PartiesManager.h"

PartiesManager::PartiesManager ()
{

}


// Parties
const std::vector<Partie*>* PartiesManager::parties () const
{
    return &m_parties;
}

void PartiesManager::addPartie (Partie *nouvellePartie)
{
    m_parties.push_back(nouvellePartie);
}
