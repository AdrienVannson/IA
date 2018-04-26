#include "JoueurFactory.hpp"

JoueurFactory::JoueurFactory (const string &nom) :
    m_nom (nom)
{
}

string JoueurFactory::nom () const
{
    return m_nom;
}

void JoueurFactory::setNom (const string &nouveauNom)
{
    m_nom = nouveauNom;
}
