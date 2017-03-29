#include "Simulateur.h"

SituationJeu Simulateur::m_situationJeu;

int Simulateur::DELTAS_DEPLACEMENTS[Simulateur::NB_DEPLACEMENTS] = {
   -1,
   1,
   -SituationJeu::NB_LIGNES,
   SituationJeu::NB_LIGNES
};


Simulateur::Simulateur ()
{

}


SituationJeu Simulateur::simulerAction (const SituationJeu &situationDepart, const Action &actionAJouer)
{
    m_situationJeu = situationDepart;
    m_situationJeu.addAction(actionAJouer);

    if ((int)m_situationJeu.actionJouees()->size() == m_situationJeu.nbJoueurs()) {

        for (const Action &action : *m_situationJeu.actionJouees()) {
            jouerAction(action);
        }

        m_situationJeu.actionJouees()->clear();
    }

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
        m_situationJeu.setCellule(nouvellePosition, (SituationJeu::Cellule)idJoueur);

    }
    else { // Élimination du joueur
        m_situationJeu.setIdVainqueur(!idJoueur); // TODO : multijoueurs
    }

}
