#include "Simulateur.h"

SituationJeu Simulateur::m_situationJeu;

int Simulateur::DELTAS_DEPLACEMENTS[Simulateur::NB_DEPLACEMENTS] = {
   -1,
   1,
   -SituationJeu::NB_COLONNES,
   SituationJeu::NB_COLONNES
};


Simulateur::Simulateur ()
{

}


SituationJeu Simulateur::simulerAction (const SituationJeu &situationDepart, const Action &actionAJouer)
{
    // Si le joueur est éliminé, on ne fait rien
    if (situationDepart.estElimine(actionAJouer.idJoueur())) {
        return situationDepart;
    }

    m_situationJeu = situationDepart;

    m_situationJeu.setCellule( m_situationJeu.positionJoueur(actionAJouer.idJoueur()), actionAJouer.idJoueur() );

    jouerAction(actionAJouer);

    return m_situationJeu;
}


void Simulateur::jouerAction (const Action &action)
{
    const int idJoueur = action.idJoueur();

    const int positionDepart = m_situationJeu.positionJoueur(idJoueur);
    const Action::Direction direction = action.direction();
    const int nouvellePosition = positionDepart + DELTAS_DEPLACEMENTS[action.direction()];


    // Vérification de la validité de l'action
    if (!(direction == Action::HAUT && positionDepart < SituationJeu::NB_COLONNES) &&
        !(direction == Action::BAS && positionDepart >= SituationJeu::NB_CELLULES - SituationJeu::NB_COLONNES) &&
        !(direction == Action::GAUCHE && positionDepart % SituationJeu::NB_COLONNES == 0) &&
        !(direction == Action::DROITE && positionDepart % SituationJeu::NB_COLONNES == SituationJeu::NB_COLONNES-1) &&
        m_situationJeu.cellule(nouvellePosition) == SituationJeu::VIDE) {

        m_situationJeu.setPositionJoueur(idJoueur, nouvellePosition);
        m_situationJeu.setCellule(nouvellePosition, idJoueur);

    }
    else { // Élimination du joueur
        m_situationJeu.eliminerJoueur(idJoueur);

        int idVainqueur = -1;

        for (int iJoueur=0; iJoueur<m_situationJeu.nbJoueurs(); iJoueur++) {
            if (!m_situationJeu.estElimine(iJoueur)) {

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
            m_situationJeu.setIdVainqueur(idVainqueur);
        }
    }

}
