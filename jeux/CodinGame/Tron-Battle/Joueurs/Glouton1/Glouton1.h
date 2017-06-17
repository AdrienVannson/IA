#ifndef GLOUTON1_H
#define GLOUTON1_H

#include "partie/Joueur/Joueur.h"


class Glouton1 : public Joueur
{

public:

    Glouton1 ();
    ~Glouton1 ();

    Joueur* clone () const;

    void startGame ();

    Action jouerAction (const InformationsTourJoueur &informations);


private:

    static const int NB_LIGNES = 20 + 2;
    static const int NB_COLONNES = 30 + 2;

    static const int NB_DEPLACEMENTS = 4;


    bool estOccupe[NB_LIGNES][NB_COLONNES];


    bool estPossible (const int iLigne, const int iColonne) const;

};

#endif // GLOUTON1_H
