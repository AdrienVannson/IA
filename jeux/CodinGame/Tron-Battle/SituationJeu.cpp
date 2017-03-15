#include "SituationJeu.h"


SituationJeu::SituationJeu (const int nbJoueurs)
{
    // Initialisation: toutes les cellules sont noires
    for (int iCellule=0; iCellule<NB_CELLULES; iCellule++) {
        m_cellules[iCellule] = VIDE;
    }

    // Initialisation des positions des joueurs
    for (int iJoueur=0; iJoueur<nbJoueurs; iJoueur++) {
        m_positionsJoueurs.push_back(0);
    }
}



// Convertions
int SituationJeu::positionCellule (const int iLigne, const int iColonne)
{
    return iLigne*NB_COLONNES + iColonne;
}



// Couleurs des cellules
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



// Position des joueurs
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
