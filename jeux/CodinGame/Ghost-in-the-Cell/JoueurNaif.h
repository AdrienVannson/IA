#ifndef JOUEURNAIF_H
#define JOUEURNAIF_H

#include "partie/Joueur.h"


class JoueurNaif : public Joueur
{

public:
    JoueurNaif ();

    virtual Action jouerAction (const InformationsTourJoueur &informations);

};

#endif // JOUEURNAIF_H
