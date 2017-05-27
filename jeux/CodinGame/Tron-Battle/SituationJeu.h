/*
 * Décrit la situation du jeu
 */

#ifndef SITUATIONJEU_H
#define SITUATIONJEU_H

#include <array>
#include <cstdio>
#include <utility>
#include <vector>

#include "Action.h"
#include "partie/SituationJeuGenerale.h"


class SituationJeu : public SituationJeuGenerale
{

public:

    // Constantes
    static const int NB_LIGNES = 20;
    static const int NB_COLONNES = 30;

    static const int NB_CELLULES = NB_LIGNES * NB_COLONNES;

    static const int VIDE = -1;


    // Constructeur
    SituationJeu (const int nbJoueurs=2);


    // Convertions
    static int positionCellule (const int iLigne, const int iColonne);

    static int ligneCellule (const int iCellule);
    static int colonneCellule (const int iCellule);
    static std::pair<int, int> coordonneesCellule (const int iCellule);


    // Couleurs des cellules
    int cellule (const int iCellule) const;
    int cellule (const int iLigne, const int iColonne) const;

    void setCellule (const int iCellule, const int nouvelleValeur);
    void setCellule (const int iLigne, const int iColonne, const int nouvelleValeur);


    // Position des joueurs
    int positionJoueur (const int iJoueur) const;

    void setPositionJoueur (const int iJoueur, const int nouvellePosition);
    void setPositionJoueur (const int iJoueur, const int nouvelleLigne, const int nouvelleColonne);


private:

    std::array<int, NB_CELLULES> m_cellules;
    std::vector<int> m_positionsJoueurs;


};

#endif // SITUATIONJEU_H
