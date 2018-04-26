#include "JoueurExterneAbstrait.hpp"

/*
 * Communication
 */

/*
 * Communication
 */

Communication::Communication (QObject *parent) :
    QObject (parent),
    m_processus (0)
{}

void Communication::demarrer (const string chemin)
{
    m_processus = new QProcess;
    m_processus->start(chemin.c_str());

    m_processus->waitForStarted(-1);
}

void Communication::envoyerDonnees (const string donnees)
{
    m_processus->write(donnees.c_str());
}

void Communication::lireDonnees ()
{
    char buffer[1024];
    qint64 longueurLue = 0;

    while (longueurLue <= 0) {
        longueurLue = m_processus->readLine(buffer, sizeof(buffer));
        qApp->processEvents();
    }

    emit donneesRecues(string(buffer));
}

void Communication::tuer ()
{
    m_processus->kill();
}


/*
 * Intermediaire
 */

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


/*
 * JoueurExterneAbstrait
 */

JoueurExterneAbstrait::JoueurExterneAbstrait (const string chemin) :
    m_chemin (chemin)
{}

JoueurExterneAbstrait::~JoueurExterneAbstrait ()
{
    m_intermediaire.tuer();
}

void JoueurExterneAbstrait::executerProgramme ()
{
    m_intermediaire.demarrer(m_chemin);
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
