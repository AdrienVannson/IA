/*
 * Informations données à un joueur pour un tour de jeu
 */

#ifndef INFORMATIONSTOURJOUEUR_H
#define INFORMATIONSTOURJOUEUR_H

#include "SituationJeu.h"


class InformationsTourJoueur
{

public:
    InformationsTourJoueur (const SituationJeu &situationJeu=SituationJeu(), const int idJoueur=0);


    const SituationJeu* situationJeu () const;
    void setSituationJeu (const SituationJeu &situationJeu=SituationJeu(), const int idJoueur=0);



private:

    SituationJeu m_situationJeu; // Une situation de jeu modifiée pour être utilisée par un joueur (masquage d'informations)


};

#endif // INFORMATIONSTOURJOUEUR_H
