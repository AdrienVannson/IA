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
    // Si le joueur est éliminé, on ne fait rien
    if (situation.estElimine(action.idJoueur())) {
        return situation;
    }

    situation.setCellule( situation.positionJoueur(action.idJoueur()), action.idJoueur() );

    const int idJoueur = action.idJoueur();

    const int positionDepart = situation.positionJoueur(idJoueur);
    const Action::Direction direction = action.direction();
    const int nouvellePosition = positionDepart + DELTAS_DEPLACEMENTS[action.direction()];


    // Vérification de la validité de l'action
    if (!(direction == Action::HAUT && positionDepart < SituationJeu::NB_COLONNES) &&
        !(direction == Action::BAS && positionDepart >= SituationJeu::NB_CELLULES - SituationJeu::NB_COLONNES) &&
        !(direction == Action::GAUCHE && positionDepart % SituationJeu::NB_COLONNES == 0) &&
        !(direction == Action::DROITE && positionDepart % SituationJeu::NB_COLONNES == SituationJeu::NB_COLONNES-1) &&
        situation.cellule(nouvellePosition) == SituationJeu::VIDE) {

        situation.setPositionJoueur(idJoueur, nouvellePosition);
        situation.setCellule(nouvellePosition, idJoueur);

    }
    else { // Élimination du joueur
        situation.eliminerJoueur(idJoueur);

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
