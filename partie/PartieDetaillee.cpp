#include "PartieDetaillee.h"

// Initialisation des membres statiques
int PartieDetaillee::m_idSuivant = 0;


PartieDetaillee::PartieDetaillee () :
    m_id(m_idSuivant++)
{

}


// ID
int PartieDetaillee::id () const
{
    return m_id;
}


// IDs des participants
std::vector<int> PartieDetaillee::idsIAs () const
{
    return m_idsIAs;
}

void PartieDetaillee::setIdsIAs (std::vector<int> nouveauIdsIAs)
{
    m_idsIAs = nouveauIdsIAs;
}


// Commentaire
std::string PartieDetaillee::commentaire () const
{
    return m_commentaire;
}

void PartieDetaillee::setCommentaire (const std::string &nouveauCommentaire)
{
    m_commentaire = nouveauCommentaire;
}
