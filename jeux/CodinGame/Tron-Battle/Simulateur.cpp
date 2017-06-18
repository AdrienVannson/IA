#include "Simulateur.h"

int Simulateur::DELTAS_DEPLACEMENTS[Simulateur::NB_DEPLACEMENTS] = {
   -1,
   1,
   -SituationJeu::NB_COLONNES,
   SituationJeu::NB_COLONNES
};


Simulateur::Simulateur ()
{
}


SituationJeu Simulateur::simulerAction (SituationJeu situation, const Action &action)
{
    const int iPlayer = situation.iPlayer();
    const int iNextPlayer = iPlayer == situation.nbJoueurs()-1 ? 0 : iPlayer + 1;
    situation.setIPlayer(iNextPlayer);

    // Si le joueur est éliminé, on ne fait rien
    if (situation.estElimine(iPlayer)) {
        return situation;
    }

    situation.setCellule(situation.positionJoueur(iPlayer), iPlayer);

    const int positionDepart = situation.positionJoueur(iPlayer);
    const Action::Direction direction = action.direction();
    const int nouvellePosition = positionDepart + DELTAS_DEPLACEMENTS[action.direction()];


    // Vérification de la validité de l'action
    if (!(direction == Action::HAUT && positionDepart < SituationJeu::NB_COLONNES) &&
        !(direction == Action::BAS && positionDepart >= SituationJeu::NB_CELLULES - SituationJeu::NB_COLONNES) &&
        !(direction == Action::GAUCHE && positionDepart % SituationJeu::NB_COLONNES == 0) &&
        !(direction == Action::DROITE && positionDepart % SituationJeu::NB_COLONNES == SituationJeu::NB_COLONNES-1) &&
        situation.cellule(nouvellePosition) == SituationJeu::VIDE) {

        situation.setPositionJoueur(iPlayer, nouvellePosition);
        situation.setCellule(nouvellePosition, iPlayer);
    }
    else { // Élimination du joueur
        situation.eliminerJoueur(iPlayer);

        int idVainqueur = -1;

        for (int iJoueur=0; iJoueur<situation.nbJoueurs(); iJoueur++) {
            if (!situation.estElimine(iJoueur)) {

                if (idVainqueur == -1) {
                    idVainqueur = iJoueur;
                }
                else { // Plusieurs joueurs sont encore en vie (la partie continue)
                    idVainqueur = -1;
                    break;
                }

            }
        }

        if (idVainqueur != -1) {
            situation.setIdVainqueur(idVainqueur);
        }
    }

    return situation;
}
