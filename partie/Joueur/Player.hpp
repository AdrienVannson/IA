/*
 * Joueur pouvant jouer au jeu
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Action.h"
#include "InformationsTourJoueur.h"


class Player
{

public:

    Player () {}
    virtual ~Player () {}


    virtual void startGame () {} // Appelé au début du jeu
    virtual void endGame () {} // Appelé à la fin du jeu

    virtual Action jouerAction (const InformationsTourJoueur &informations) = 0;

};

#endif // PLAYER_H
