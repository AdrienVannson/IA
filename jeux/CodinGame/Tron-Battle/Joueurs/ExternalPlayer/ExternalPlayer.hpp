#ifndef EXTERNALPLAYER_HPP
#define EXTERNALPLAYER_HPP

#include "partie/Joueur/Joueur.h"


class ExternalPlayer : public Joueur
{

public:

    ExternalPlayer ();
    ~ExternalPlayer ();

    Joueur* clone () const;

    Action jouerAction (const InformationsTourJoueur &informations);

};

#endif // EXTERNALPLAYER_HPP
