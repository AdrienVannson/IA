/*
 * Gère les parties
 *
 * Les parties ajoutées ne peuvent plus être modifiées par la suite
 */

#ifndef PARTIESMANAGER_H
#define PARTIESMANAGER_H

#include <vector>

#include "Partie.h"


class PartiesManager
{

public:
    PartiesManager ();

    const std::vector<Partie*>* parties () const;
    Partie* getPartie (const int idPartie);
    void addPartie (Partie *nouvellePartie);


private:
    std::vector<Partie*> m_parties;

};

#endif // PARTIESMANAGER_H
