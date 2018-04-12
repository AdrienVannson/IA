#ifndef JOUEUREXTERNEABSTRAIT_HPP
#define JOUEUREXTERNEABSTRAIT_HPP

#include <QProcess>

#include <iostream>
#include <string>

#include "partie/Joueur/Joueur.hpp"

using namespace std;


class JoueurExterneAbstrait : public Joueur
{

public:
    JoueurExterneAbstrait (const string &chemin);
    ~JoueurExterneAbstrait ();

    void demarrerProg ();

protected:
    string getLine ();
    void send (const string &donnees);

private:
    std::string m_chemin;
    QProcess *m_processus;

};

#endif // JOUEUREXTERNEABSTRAIT_HPP
