#ifndef PLAYER_H
#define PLAYER_H

#include "Action.hpp"
#include "InformationsTourJoueur.h"


class Joueur
{

public:

    Joueur () {}
    virtual ~Joueur () {}


    virtual void startGame () {} // Appelé au début du jeu
    virtual void endGame () {} // Appelé à la fin du jeu

    virtual Action jouerAction (const InformationsTourJoueur &informations) = 0;

};

#endif // PLAYER_H
