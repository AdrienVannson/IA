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
        const int iCellule = rand() % (NB_LIGNES*NB_COLONNES);
        m_positionsJoueurs.push_back(iCellule);
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
    if (iCellule == INVALIDE) {
        return INVALIDE;
    }
    return iCellule / NB_COLONNES;
}

int SituationJeu::colonneCellule (const int iCellule)
{
    if (iCellule == INVALIDE) {
        return INVALIDE;
    }
    return iCellule % NB_COLONNES;
}

std::pair<int, int> SituationJeu::coordonneesCellule (const int iCellule)
{
    return std::make_pair(ligneCellule(iCellule), colonneCellule(iCellule));
}



/*
 * Couleurs des cellules
 */

int SituationJeu::cellule (const int iCellule) const
{
    return m_cellules[iCellule];
}

int SituationJeu::cellule (const int iLigne, const int iColonne) const
{
    return cellule(positionCellule(iLigne, iColonne));
}


void SituationJeu::setCellule (const int iCellule, const int nouvelleValeur)
{
    m_cellules[iCellule] = nouvelleValeur;
}

void SituationJeu::setCellule (const int iLigne, const int iColonne, const int nouvelleValeur)
{
    setCellule(positionCellule(iLigne, iColonne), nouvelleValeur);
}



/*
 * Joueurs
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


bool SituationJeu::estElimine (const int idJoueur) const
{
    return positionJoueur(idJoueur) == INVALIDE;
}

void SituationJeu::eliminerJoueur (const int idJoueur)
{
    setPositionJoueur(idJoueur, INVALIDE);
    for (int iCellule=0; iCellule<NB_CELLULES; iCellule++) {
        if (m_cellules[iCellule] == idJoueur) {
            m_cellules[iCellule] = -1;
        }
    }
}
