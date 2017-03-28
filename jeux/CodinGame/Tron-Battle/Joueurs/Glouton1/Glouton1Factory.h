#ifndef GLOUTON1FACTORY_H
#define GLOUTON1FACTORY_H


#include "partie/Joueur/JoueurFactory.h"
#include "Glouton1.h"


class Glouton1Factory : public JoueurFactory
{

public:

    Glouton1Factory ();

    Joueur* getJoueur () const;


};

#endif // GLOUTON1FACTORY_H
