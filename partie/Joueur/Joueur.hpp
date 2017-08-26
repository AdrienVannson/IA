#ifndef PLAYER_H
#define PLAYER_H

#include "Action.hpp"
#include "InfosTour.hpp"


class Joueur
{

public:

    Joueur () {}
    virtual ~Joueur () {}

    virtual Action jouerAction (const InfosTour &informations) = 0;

};

#endif // PLAYER_H
