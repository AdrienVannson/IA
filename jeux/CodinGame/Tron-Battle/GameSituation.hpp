/*
 * Décrit la situation du jeu
 */

#ifndef GAMESITUATION_HPP
#define GAMESITUATION_HPP

#include <array>
#include <cstdio>
#include <utility>
#include <vector>

#include "Action.hpp"
#include "partie/AbstractGameSituation.hpp"


class GameSituation : public AbstractGameSituation
{

public:

    // Constantes
    static const int NB_LIGNES = 20;
    static const int NB_COLONNES = 30;

    static const int NB_CELLULES = NB_LIGNES * NB_COLONNES;

    static const int VIDE = -1;
    static const int INVALIDE = -1;


    // Constructeur
    GameSituation (const int nbJoueurs=2);


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


    // Joueurs
    int positionJoueur (const int iJoueur) const;

    void setPositionJoueur (const int iJoueur, const int nouvellePosition);
    void setPositionJoueur (const int iJoueur, const int nouvelleLigne, const int nouvelleColonne);

    bool estElimine (const int idJoueur) const;
    void eliminerJoueur (const int idJoueur);


private:

    std::array<short, NB_CELLULES> m_cellules;
    std::vector<int> m_positionsJoueurs;


};

#endif // GAMESITUATION_HPP