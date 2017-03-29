#ifndef JOUEURFACTORY_H
#define JOUEURFACTORY_H


#include "Joueur.h"


class JoueurFactory
{

public:

    JoueurFactory ();

    virtual Joueur* creerJoueur () const = 0;


};

#endif // JOUEURFACTORY_H
