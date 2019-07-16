#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "Action.hpp"
#include "Partie.hpp"
#include "unused.hpp"


class Joueur
{
public:
    Joueur ();
    virtual ~Joueur ();

    virtual void debutPartie (const Partie &partie, const int idJoueur);
    virtual Action jouerAction (const Partie &partie, const int idJoueur) = 0;

};

#endif // JOUEUR_HPP
