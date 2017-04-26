#include "SituationJeu.h"


SituationJeu::SituationJeu (const int nbJoueurs) :
    SituationJeuGenerale (nbJoueurs)
{
    // Initialisation: toutes les cellules sont noires
    for (int iCellule=0; iCellule<NB_CELLULES; iCellule++) {
        m_cellules[iCellule] = VIDE;
    }

    // Initialisation des positions des joueurs
    for (int iJoueur=0; iJoueur<nbJoueurs; iJoueur++) {
        const int position = rand() % (NB_LIGNES*NB_COLONNES);
        m_positionsJoueurs.push_back(position);
    }
}




/*
 * Convertions
 */

int SituationJeu::positionCellule (const int iLigne, const int iColonne)
{
    return iLigne*NB_COLONNES + iColonne;
}


int SituationJeu::ligneCellule (const int iCellule)
{
    return iCellule / NB_COLONNES;
}

int SituationJeu::colonneCellule (const int iCellule)
{
    return iCellule % NB_COLONNES;
}

std::pair<int, int> SituationJeu::coordonneesCellule (const int iCellule)
{
    return std::make_pair(ligneCellule(iCellule), colonneCellule(iCellule));
}



/*
 * Couleurs des cellules
 */

SituationJeu::Cellule SituationJeu::cellule (const int iCellule) const
{
    return m_cellules[iCellule];
}

SituationJeu::Cellule SituationJeu::cellule (const int iLigne, const int iColonne) const
{
    return cellule(positionCellule(iLigne, iColonne));
}


void SituationJeu::setCellule (const int iCellule, const Cellule nouvelleCellule)
{
    m_cellules[iCellule] = nouvelleCellule;
}

void SituationJeu::setCellule (const int iLigne, const int iColonne, const Cellule nouvelleCellule)
{
    setCellule(positionCellule(iLigne, iColonne), nouvelleCellule);
}



/*
 * Position des joueurs
 */

int SituationJeu::positionJoueur (const int iJoueur) const
{
    return m_positionsJoueurs[iJoueur];
}

void SituationJeu::setPositionJoueur (const int iJoueur, const int nouvellePosition)
{
    m_positionsJoueurs[iJoueur] = nouvellePosition;
}

void SituationJeu::setPositionJoueur (const int iJoueur, const int nouvelleLigne, const int nouvelleColonne)
{
    setPositionJoueur(iJoueur, positionCellule(nouvelleLigne, nouvelleColonne));
}



/*
 * Actions jouées
 */

const std::vector<Action>* SituationJeu::actionJouees () const
{
    return &m_actionsJouees;
}

std::vector<Action>* SituationJeu::actionJouees ()
{
    return &m_actionsJouees;
}

void SituationJeu::addAction (const Action &nouvelleAction)
{
    m_actionsJouees.push_back(nouvelleAction);
}
