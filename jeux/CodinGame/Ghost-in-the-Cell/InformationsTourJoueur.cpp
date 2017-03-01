#include "InformationsTourJoueur.h"

InformationsTourJoueur::InformationsTourJoueur (const SituationJeu &situationJeu, const int idJoueur)
{
    setSituationJeu(situationJeu, idJoueur);
}


const SituationJeu* InformationsTourJoueur::situationJeu () const
{
    return &m_situationJeu;
}

void InformationsTourJoueur::setSituationJeu (const SituationJeu &situationJeu, const int idJoueur)
{
    m_situationJeu = situationJeu;

    // Actions
    m_situationJeu.supprimerLesActions();

    // Troupes
    for (SituationJeu::Troupe &troupe : *m_situationJeu.troupes()) {

        // Propriétaire
        if (troupe.m_idJoueur == -1) { // Troupe neutre
            troupe.m_idJoueur = 0;
        }
        else if (troupe.m_idJoueur == idJoueur) { // Troupe du joueur
            troupe.m_idJoueur = 1;
        }
        else { // Troupe adverse
            troupe.m_idJoueur = -1;
        }

        // Bombe
        if (troupe.m_estBombe && troupe.m_idJoueur == -1) {
            troupe.m_cible = -1;
            troupe.m_nbToursRestants = -1;
        }

    }

    // Usines
    for (SituationJeu::Usine &usine : *m_situationJeu.usines()) {

        // Propriétaire
        if (usine.m_proprietaire == -1) { // Troupe neutre
            usine.m_proprietaire = 0;
        }
        else if (usine.m_proprietaire == idJoueur) { // Troupe du joueur
            usine.m_proprietaire = 1;
        }
        else { // Troupe adverse
            usine.m_proprietaire = -1;
        }

    }
}
