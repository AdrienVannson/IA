/*
 * Décrit une action réalisée par un joueur
 */

#ifndef ACTION_H
#define ACTION_H


class Action
{

public:
    Action ();

    int idJoueur () const;
    void setIdJoueur (const int nouvelIdJoueur);


private:

    // ID du joueur ayant réalisé l'action
    int m_idJoueur;

};

#endif // ACTION_H
