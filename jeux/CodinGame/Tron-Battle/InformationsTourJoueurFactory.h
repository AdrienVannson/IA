#ifndef INFORMATIONSTOURJOUEURFACTORY_H
#define INFORMATIONSTOURJOUEURFACTORY_H

#include "InformationsTourJoueur.h"
#include "partie/Game.hpp"


class InformationsTourJoueurFactory
{

public:

    InformationsTourJoueurFactory ();

    static InformationsTourJoueur creerInformationsTourJoueur (const Game &partie, const int idJoueur);

};

#endif // INFORMATIONSTOURJOUEURFACTORY_H
