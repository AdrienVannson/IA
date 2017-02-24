/*
 * Décrit la situation du jeu
 */

#ifndef SITUATIONJEU_H
#define SITUATIONJEU_H

#include <array>
#include <vector>


class SituationJeu
{

public:

    static const int NB_LIGNES = 20;
    static const int NB_COLONNES = 30;

    static const int NB_CELLULES = NB_LIGNES * NB_COLONNES;


    SituationJeu (const int nbJoueurs = 2);

    // Convertions
    static int positionCellule (const int iLigne, const int iColonne);

    // Couleurs des cellules
    char cellule (const int iCellule) const;
    char cellule (const int iLigne, const int iColonne) const;

    void setCellule (const int iCellule, const char nouvelleCouleur);
    void setCellule (const int iLigne, const int iColonne, const char nouvelleCouleur);

    // Position des joueurs
    int positionJoueur (const int iJoueur) const;

    void setPositionJoueur (const int iJoueur, const int nouvellePosition);
    void setPositionJoueur (const int iJoueur, const int nouvelleLigne, const int nouvelleColonne);


private:

    // Description des cellules en binaire: 00 = vide, 01 = bleu, 10 = rouge
    std::array<char, NB_CELLULES> m_cellules;
    std::vector<int> m_positionsJoueurs;


};

#endif // SITUATIONJEU_H
