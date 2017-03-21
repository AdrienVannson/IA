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

    const int nouvellePosition = m_situationJeu.positionJoueur(idJoueur) + DELTAS_DEPLACEMENTS[action.direction()];

    if (m_situationJeu.cellule(nouvellePosition)) { // Action valide
        m_situationJeu.setPositionJoueur(idJoueur, nouvellePosition);
        m_situationJeu.setCellule(nouvellePosition, (SituationJeu::Cellule)idJoueur);
    }
    else { // Élimination du joueur

    }

}
