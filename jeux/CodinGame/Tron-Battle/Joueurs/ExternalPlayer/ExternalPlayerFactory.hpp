#ifndef EXTERNALPLAYERFACTORY_HPP
#define EXTERNALPLAYERFACTORY_HPP

#include "partie/Joueur/PlayerFactory.hpp"
#include "ExternalPlayer.hpp"


class ExternalPlayerFactory : public PlayerFactory
{

public:

    ExternalPlayerFactory ();

    std::shared_ptr<Player> getNewPlayer () const;


};

#endif // EXTERNALPLAYERFACTORY_HPP
