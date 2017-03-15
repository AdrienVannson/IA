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

    // Constantes
    static const int NB_LIGNES = 20;
    static const int NB_COLONNES = 30;

    static const int NB_CELLULES = NB_LIGNES * NB_COLONNES;

    enum Cellule
    {
        VIDE = 0,
        JOUEUR_1 = 1,
        JOUEUR_2 = 2,
        JOUEUR_3 = 4,
        JOUEUR_4 = 8
    };


    // Constructeur
    SituationJeu (const int nbJoueurs = 2);


    // Fin de la partie
    bool estFini () const;
    int idVainqueur () const;


    // Convertions
    static int positionCellule (const int iLigne, const int iColonne);


    // Couleurs des cellules
    Cellule cellule (const int iCellule) const;
    Cellule cellule (const int iLigne, const int iColonne) const;

    void setCellule (const int iCellule, const Cellule nouvelleCellule);
    void setCellule (const int iLigne, const int iColonne, const Cellule nouvelleCellule);


    // Position des joueurs
    int positionJoueur (const int iJoueur) const;

    void setPositionJoueur (const int iJoueur, const int nouvellePosition);
    void setPositionJoueur (const int iJoueur, const int nouvelleLigne, const int nouvelleColonne);


private:

    // Description des cellules en binaire: 00 = vide, 01 = bleu, 10 = rouge
    std::array<Cellule, NB_CELLULES> m_cellules;
    std::vector<int> m_positionsJoueurs;

    bool m_estPartieFinie;


};

#endif // SITUATIONJEU_H
