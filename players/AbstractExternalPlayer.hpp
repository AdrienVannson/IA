#ifndef ABSTRACTEXTERNALPLAYER_HPP
#define ABSTRACTEXTERNALPLAYER_HPP

#include <QDebug> // TODEL

#include <ext/stdio_filebuf.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <memory>
#include <exception>
#include <string>

#include "partie/Joueur/Player.hpp"

class spawn;


class AbstractExternalPlayer : public Player
{

public:

    AbstractExternalPlayer (const std::string &chemin="");
    ~AbstractExternalPlayer ();


    void startGame ();
    void endGame ();

    void setChemin (const std::string &chemin);


protected:

    std::string getLine ();
    void send (const std::string &data);


private:

    std::string m_chemin;
    spawn *m_prog;

};

#endif // ABSTRACTEXTERNALPLAYER_HPP
