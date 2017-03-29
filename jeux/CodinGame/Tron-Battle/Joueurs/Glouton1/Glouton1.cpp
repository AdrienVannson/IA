#include "Glouton1.h"


Glouton1::Glouton1 ()
{
    for (int iLigne=0; iLigne<NB_LIGNES; iLigne++) {
        for (int iColonne=0; iColonne<NB_COLONNES; iColonne++) {
            estOccupe[iLigne][iColonne] = false;
        }
    }


    for (int iColonne=0; iColonne<NB_COLONNES; iColonne++) {
        estOccupe[0][iColonne] = true;
        estOccupe[NB_LIGNES-1][iColonne] = true;
    }

    for (int iLigne=0; iLigne<NB_LIGNES; iLigne++) {
        estOccupe[iLigne][0] = true;
        estOccupe[iLigne][NB_COLONNES-1] = true;
    }
}

Glouton1::~Glouton1 ()
{
}

Action Glouton1::jouerAction (const InformationsTourJoueur &informations)
{
    for (unsigned int iJoueur=0; iJoueur<informations.m_joueurs.size(); iJoueur++) {
        std::pair<int, int> coordonnees = informations.m_joueurs[iJoueur].second;

        estOccupe[coordonnees.first+1][coordonnees.second+1] = true;
    }


    const int iLigne = informations.m_joueurs[informations.m_idJoueur].second.first + 1; // +1 pour prendre en compte les barrières
    const int iColonne = informations.m_joueurs[informations.m_idJoueur].second.second + 1;


    Action action;

    for (int iDirection=0; iDirection<NB_DEPLACEMENTS; iDirection++) {
        Action::Direction direction = (Action::Direction) iDirection;

        if (direction == Action::GAUCHE && estPossible(iLigne, iColonne-1)) {
            action.setDirection(Action::GAUCHE);
        }

        if (direction == Action::DROITE && estPossible(iLigne, iColonne+1)) {
            action.setDirection(Action::DROITE);
        }

        if (direction == Action::HAUT && estPossible(iLigne-1, iColonne)) {
            action.setDirection(Action::HAUT);
        }

        if (direction == Action::BAS && estPossible(iLigne+1, iColonne)) {
            action.setDirection(Action::BAS);
        }
    }

    return action;
}


bool Glouton1::estPossible (const int iLigne, const int iColonne) const
{
    if (iLigne < 0 || iLigne >= NB_LIGNES || iColonne < 0 || iColonne >= NB_COLONNES) {
        return false;
    }

    if (estOccupe[iLigne][iColonne]) {
        return false;
    }

    return true;
}
