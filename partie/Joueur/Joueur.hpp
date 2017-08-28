#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Action.hpp"
#include "InfosTour.hpp"
#include "InfosDebutPartie.hpp"
#include "unused.hpp"


class Joueur
{

public:

    Joueur ();
    virtual ~Joueur ();

    virtual void debutPartie (const InfosDebutPartie &infos);
    virtual Action jouerAction (const InfosTour &informations) = 0;


};

#endif // PLAYER_H
