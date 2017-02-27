#include "Simulateur.h"

Simulateur::Simulateur ()
{

}


SituationJeu Simulateur::simulerAction (const SituationJeu &situationDepart, const Action actionAJouer)
{
    m_situation = situationDepart;
    m_situation.ajouterAction(actionAJouer);

    if (m_situation.actions()->size() == 2) { // Si tous les joueurs ont joué, simulation du tour

        avancerTroupes();

        for (const Action &action : *m_situation.actions()) {
            executerAction(action);
        }

        produireUnites();
        combattre();
        exploserBombes();
        verifierFin();

    }

    return m_situation;
}


/*
 * Fonctions de jeu
 */

void Simulateur::avancerTroupes ()
{
    for (SituationJeu::Troupe &troupe : *m_situation.troupes()) {
        troupe.nbToursRestants--;
    }
}

void Simulateur::executerAction (const Action &action)
{

}

void Simulateur::produireUnites ()
{
    for (SituationJeu::Usine &usine : *m_situation.usines()) {

        if (usine.nbToursBloquesRestants > 0) {
            usine.nbToursBloquesRestants--;
        }
        else if (usine.m_proprietaire != SituationJeu::NEUTRE) {
            usine.m_nbUnites += usine.m_production;
        }

    }
}

void Simulateur::combattre ()
{

}

void Simulateur::exploserBombes ()
{

}

bool Simulateur::verifierFin ()
{

}
