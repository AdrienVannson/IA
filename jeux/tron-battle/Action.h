/*
 * Décrit une action réalisée par un joueur
 */

#ifndef ACTION_H
#define ACTION_H

#include "config.h"


class Action
{

public:

    Action ();

    int idJoueur () const;
    void setIdJoueur (const int nouvelIdJoueur);


    enum Direction {
        GAUCHE,
        DROITE,
        HAUT,
        BAS
    };

    Direction direction () const;
    void setDirection (const Direction nouvelleDirection);


private:

    // ID du joueur ayant réalisé l'action
    int m_idJoueur;

    Direction m_direction;

};

#endif // ACTION_H
