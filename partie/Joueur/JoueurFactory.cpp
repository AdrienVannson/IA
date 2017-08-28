#include "JoueurFactory.hpp"

JoueurFactory::JoueurFactory (const std::string &nom) :
    m_nom (nom)
{
}

std::string JoueurFactory::nom () const
{
    return m_nom;
}

void JoueurFactory::setNom (const std::string &nouveauNom)
{
    m_nom = nouveauNom;
}
