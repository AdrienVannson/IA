/*
 * Joueur pouvant jouer au jeu
 */

#ifndef JOUEUR_H
#define JOUEUR_H

#include "Action.h"
#include "InformationsTourJoueur.h"


class Joueur
{

public:
    Joueur ();

    virtual Action jouerAction (const InformationsTourJoueur &informations) = 0;

};

#endif // JOUEUR_H
