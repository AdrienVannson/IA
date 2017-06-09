#include "JoueursManager.h"

JoueursManager::JoueursManager ()
{
}

JoueursManager::~JoueursManager ()
{
    for (std::pair<const Joueur*, double> paire : m_joueurs) {
        delete paire.first;
    }
}


void JoueursManager::addJoueur (const Joueur *nouveauJoueur)
{
    m_joueurs.push_back( std::make_pair(nouveauJoueur, -1) );

    if (m_joueurs.size() >= 100) { // Suppression des joueurs trop nombreux
        delete m_joueurs[0].first;
        m_joueurs.erase(m_joueurs.begin());
    }
}


int JoueursManager::nbJoueurs () const
{
    return m_joueurs.size();
}

Joueur* JoueursManager::getJoueur (const int idJoueur) const
{
    return m_joueurs[idJoueur].first->clone();
}
