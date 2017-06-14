#include "PartieDecrite.h"

// Initialisation des membres statiques
int PartieDecrite::m_idSuivant = 0;


PartieDecrite::PartieDecrite () :
    m_id(m_idSuivant++)
{

}

PartieDecrite::PartieDecrite (const Partie &partie) :
    Partie (partie)
{

}


// ID
int PartieDecrite::id () const
{
    return m_id;
}


// IDs des participants
std::vector<int> PartieDecrite::idsIAs () const
{
    return m_idsIAs;
}

void PartieDecrite::setIdsIAs (std::vector<int> nouveauIdsIAs)
{
    m_idsIAs = nouveauIdsIAs;
}


// Commentaire
std::string PartieDecrite::commentaire () const
{
    return m_commentaire;
}

void PartieDecrite::setCommentaire (const std::string &nouveauCommentaire)
{
    m_commentaire = nouveauCommentaire;
}
