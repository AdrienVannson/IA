#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Action.hpp"
#include "Partie.hpp"
#include "InfosTour.hpp"
#include "unused.hpp"


class Joueur
{

public:

    Joueur ();
    virtual ~Joueur ();

    virtual void debutPartie (const Partie &partie, const int idJoueur);
    virtual Action jouerAction (const InfosTour &informations) = 0;


};

#endif // PLAYER_H
