#include "DescribedGame.hpp"

// Initialisation des membres statiques
int DescribedGame::m_idSuivant = 0;


DescribedGame::DescribedGame () :
    m_id(m_idSuivant++)
{

}

DescribedGame::DescribedGame (const Game &partie) :
    Game (partie)
{

}


// ID
int DescribedGame::id () const
{
    return m_id;
}


// IDs des participants
std::vector<int> DescribedGame::idsIAs () const
{
    return m_idsIAs;
}

void DescribedGame::setIdsIAs (std::vector<int> nouveauIdsIAs)
{
    m_idsIAs = nouveauIdsIAs;
}


// Commentaire
std::string DescribedGame::commentaire () const
{
    return m_commentaire;
}

void DescribedGame::setCommentaire (const std::string &nouveauCommentaire)
{
    m_commentaire = nouveauCommentaire;
}
