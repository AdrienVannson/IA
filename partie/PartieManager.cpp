#include "PartieManager.h"

PartieManager::PartieManager()
{

}


// Parties
std::vector<Partie*> PartieManager::parties () const
{
    return m_parties;
}

void PartieManager::addPartie (Partie *nouvellePartie)
{
    m_parties.push_back(nouvellePartie);
}
