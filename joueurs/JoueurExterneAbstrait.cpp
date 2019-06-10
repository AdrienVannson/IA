#include "JoueurExterneAbstrait.hpp"

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

    connect(m_processus, &QProcess::readyReadStandardOutput, this, &Communication::lireDonnees);
    connect(m_processus, &QProcess::readyReadStandardError, this, &Communication::lireErreur);

    connect(m_processus, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &Communication::termine);

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

    while (m_processus->readLine(buffer, sizeof(buffer))) {
        emit donneesRecues(string(buffer));
    }
}

void Communication::lireErreur ()
{
    cerr << m_processus->readAllStandardError().toStdString();
}

void Communication::tuer ()
{
    m_processus->kill();
}

void Communication::termine (int exitCode, QProcess::ExitStatus exitStatus)
{
    cerr << "FIN PROG " << exitCode << " " << exitStatus << endl;
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
    m_lignes.push(donnees);
}

void Intermediaire::envoyerDonnees (const string donnees)
{
    emit donneesEnvoyees(donnees);
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
    QThread::msleep(5);

    while (m_intermediaire.m_lignes.empty()) {
        qApp->processEvents();
        QThread::msleep(50);
    }

    string donnees = m_intermediaire.m_lignes.front();
    m_intermediaire.m_lignes.pop();

    return donnees;
}

void JoueurExterneAbstrait::send (const string &donnees)
{
    m_intermediaire.envoyerDonnees(donnees);
}
