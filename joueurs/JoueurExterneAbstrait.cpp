#include "JoueurExterneAbstrait.hpp"

Intermediaire::Intermediaire (QObject *parent) :
    QObject (parent)
{}

void Intermediaire::demarrer (const string &chemin)
{
    emit debut(chemin);
}

void Intermediaire::recevoirDonnees (const string donnees)
{
    m_donnees = donnees;
}

void Intermediaire::envoyerDonnees (const string donnees)
{
    emit donneesEnvoyees(donnees);
}

void Intermediaire::lire ()
{
    emit doitLire();
}

void Intermediaire::tuer ()
{
    emit doitTuer();
}


JoueurExterneAbstrait::JoueurExterneAbstrait ()
{}

JoueurExterneAbstrait::~JoueurExterneAbstrait ()
{
    m_intermediaire.tuer();
}

string JoueurExterneAbstrait::getLine ()
{
    m_intermediaire.lire();

    while (m_intermediaire.m_donnees.empty()) {
        qApp->processEvents();
    }

    string donnees = m_intermediaire.m_donnees;
    m_intermediaire.m_donnees.clear();

    return donnees;
}

void JoueurExterneAbstrait::send (const string &donnees)
{
    m_intermediaire.envoyerDonnees(donnees);
}
