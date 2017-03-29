#ifndef INFORMATIONSTOURJOUEURFACTORY_H
#define INFORMATIONSTOURJOUEURFACTORY_H

#include "InformationsTourJoueur.h"
#include "partie/Partie.h"


class InformationsTourJoueurFactory
{

public:

    InformationsTourJoueurFactory ();

    static InformationsTourJoueur creerInformationsTourJoueur (const Partie &partie, const int idJoueur);

};

#endif // INFORMATIONSTOURJOUEURFACTORY_H
