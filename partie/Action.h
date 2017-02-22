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


private:

    // ID du joueur ayant réalisé l'action
    int m_idJoueur;


// Inclut les informations supplémentaires du jeu utilisé
#include xstr(jeux/JEU/Action.h)
};

#endif // ACTION_H
