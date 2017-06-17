#ifndef EXTERNALPLAYER_HPP
#define EXTERNALPLAYER_HPP

#include <QDebug>

#include <ext/stdio_filebuf.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <memory>
#include <exception>

#include "partie/Joueur/Joueur.h"

class spawn;

class ExternalPlayer : public Joueur
{

public:

    ExternalPlayer (const std::string &chemin="");
    ~ExternalPlayer ();

    Joueur* clone () const;


    void startGame ();
    void endGame ();

    Action jouerAction (const InformationsTourJoueur &informations);

    void setChemin (const std::string &chemin);


private:

    std::string m_chemin;
    spawn *m_prog;

};

#endif // EXTERNALPLAYER_HPP
