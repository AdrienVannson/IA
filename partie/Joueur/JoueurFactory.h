#ifndef JOUEURFACTORY_H
#define JOUEURFACTORY_H


#include "Player.hpp"


class JoueurFactory
{

public:

    JoueurFactory ();

    virtual Player* creerJoueur () const = 0;


};

#endif // JOUEURFACTORY_H
