#ifndef ABSTRACTEXTERNALPLAYER_HPP
#define ABSTRACTEXTERNALPLAYER_HPP

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


    void setChemin (const std::string &chemin);


protected:

    std::string getLine ();
    void send (const std::string &data);


private:

    std::string m_chemin;
    spawn *m_prog;

};

#endif // ABSTRACTEXTERNALPLAYER_HPP
