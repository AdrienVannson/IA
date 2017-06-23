#ifndef GLOUTON1FACTORY_H
#define GLOUTON1FACTORY_H


#include "partie/Joueur/PlayerFactory.hpp"
#include "Glouton1.h"


class Glouton1Factory : public PlayerFactory
{

public:

    Glouton1Factory ();

    std::shared_ptr<Player> getNewPlayer () const;


};

#endif // GLOUTON1FACTORY_H
