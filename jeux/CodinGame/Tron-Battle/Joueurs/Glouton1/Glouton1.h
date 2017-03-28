#ifndef GLOUTON1_H
#define GLOUTON1_H

#include "partie/Joueur/Joueur.h"


class Glouton1 : public Joueur
{

public:

    Glouton1 ();
    ~Glouton1 ();

    Action jouerAction (const InformationsTourJoueur &informations);


};

#endif // GLOUTON1_H
