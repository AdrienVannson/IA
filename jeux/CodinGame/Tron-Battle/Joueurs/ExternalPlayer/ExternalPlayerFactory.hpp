#ifndef EXTERNALPLAYERFACTORY_HPP
#define EXTERNALPLAYERFACTORY_HPP

#include "partie/Joueur/JoueurFactory.h"
#include "ExternalPlayer.hpp"


class ExternalPlayerFactory : public JoueurFactory
{

public:

    ExternalPlayerFactory ();

    Joueur* creerJoueur () const;


};

#endif // EXTERNALPLAYERFACTORY_HPP
