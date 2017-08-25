#ifndef PLAYERFACTORY_HPP
#define PLAYERFACTORY_HPP

#include <memory>

#include "Joueur.hpp"


class JoueurFactory
{

public:

    JoueurFactory ();

    virtual std::shared_ptr<Joueur> getNewPlayer () const = 0;


};

#endif // PLAYERFACTORY_HPP
