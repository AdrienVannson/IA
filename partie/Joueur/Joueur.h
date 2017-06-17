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
    virtual ~Joueur ();

    virtual Joueur* clone () const = 0;


    virtual void startGame (); // Appelé au début du jeu
    virtual void endGame (); // Appelé à la fin du jeu

    virtual Action jouerAction (const InformationsTourJoueur &informations) = 0;

};

#endif // JOUEUR_H
