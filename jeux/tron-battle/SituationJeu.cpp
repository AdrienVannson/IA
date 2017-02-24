#include "SituationJeu.h"


SituationJeu::SituationJeu (const int nbJoueurs)
{
    // Initialisation: toutes les cellules sont noires
    for (int iCellule=0; iCellule<NB_CELLULES; iCellule++) {
        m_cellules[iCellule] = 0;
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
char SituationJeu::cellule (const int iCellule) const
{
    return m_cellules[iCellule];
}

char SituationJeu::cellule (const int iLigne, const int iColonne) const
{
    return cellule(positionCellule(iLigne, iColonne));
}


void SituationJeu::setCellule (const int iCellule, const char nouvelleCouleur)
{
    m_cellules[iCellule] = nouvelleCouleur;
}

void SituationJeu::setCellule (const int iLigne, const int iColonne, const char nouvelleCouleur)
{
    setCellule(positionCellule(iLigne, iColonne), nouvelleCouleur);
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
