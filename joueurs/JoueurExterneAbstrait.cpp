#include "JoueurExterneAbstrait.hpp"

Intermediaire::Intermediaire (QObject *parent) :
    QObject (parent)
{}

void Intermediaire::recevoirDonnees (const string donnees)
{
    cerr << "ARRIVEE: " << donnees.size() << endl;
    cerr << donnees << endl;
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


JoueurExterneAbstrait::JoueurExterneAbstrait ()
{}

JoueurExterneAbstrait::~JoueurExterneAbstrait ()
{}

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
