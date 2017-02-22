/*
 * Gère les parties
 *
 * Les parties ajoutées ne peuvent plus être modifiées par la suite
 */

#ifndef PARTIEMANAGER_H
#define PARTIEMANAGER_H

#include <vector>

#include "Partie.h"


class PartieManager
{

public:
    PartieManager ();

    std::vector<Partie*> parties () const;
    void addPartie (Partie *nouvellePartie);


private:
    std::vector<Partie*> m_parties;

};

#endif // PARTIEMANAGER_H
