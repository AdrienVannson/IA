#ifndef JOUEUREXTERNEABSTRAIT_HPP
#define JOUEUREXTERNEABSTRAIT_HPP

#include <ext/stdio_filebuf.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <memory>
#include <exception>
#include <string>

#include "partie/Joueur/Joueur.hpp"

class spawn;


class JoueurExterneAbstrait : public Joueur
{

public:

    JoueurExterneAbstrait (const std::string &chemin="");
    ~JoueurExterneAbstrait ();


protected:

    void demarrerProg ();

    std::string getLine ();
    void send (const std::string &data);


private:

    std::string m_chemin;
    spawn *m_prog;

};

#endif // JOUEUREXTERNEABSTRAIT_HPP
