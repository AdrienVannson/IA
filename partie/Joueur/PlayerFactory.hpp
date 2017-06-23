#ifndef PLAYERFACTORY_HPP
#define PLAYERFACTORY_HPP

#include <memory>

#include "Player.hpp"


class PlayerFactory
{

public:

    PlayerFactory ();

    virtual std::shared_ptr<Player> getNewPlayer () const = 0;


};

#endif // PLAYERFACTORY_HPP
