#ifndef JOUEURFACTORY_H
#define JOUEURFACTORY_H


#include "Joueur.h"


class JoueurFactory
{

public:

    JoueurFactory ();

    virtual Joueur* getJoueur () const = 0;


};

#endif // JOUEURFACTORY_H
