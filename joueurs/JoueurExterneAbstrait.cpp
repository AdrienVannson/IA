#include "JoueurExterneAbstrait.hpp"

JoueurExterneAbstrait::JoueurExterneAbstrait (const string &chemin) :
    m_chemin (chemin)
{
    m_processus = new QProcess;
}

JoueurExterneAbstrait::~JoueurExterneAbstrait ()
{
    m_processus->kill();
}

void JoueurExterneAbstrait::demarrerProg ()
{
    m_processus->start(m_chemin.c_str());
}

string JoueurExterneAbstrait::getLine ()
{
    char buffer[1024];
    qint64 longueurLue = m_processus->readLine(buffer, sizeof(buffer));

    if (longueurLue == -1) {
        cerr << "Error" << endl;
    }

    return string (buffer);
}

void JoueurExterneAbstrait::send (const string &donnees)
{
    m_processus->write(donnees.c_str());
}
