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

    enum Cellule
    {
        VIDE = -1,
        JOUEUR_1 = 0,
        JOUEUR_2 = 1,
        JOUEUR_3 = 2,
        JOUEUR_4 = 3
    };


    // Constructeur
    SituationJeu (const int nbJoueurs=2);


    // Convertions
    static int positionCellule (const int iLigne, const int iColonne);

    static int ligneCellule (const int iCellule);
    static int colonneCellule (const int iCellule);
    static std::pair<int, int> coordonneesCellule (const int iCellule);


    // Couleurs des cellules
    Cellule cellule (const int iCellule) const;
    Cellule cellule (const int iLigne, const int iColonne) const;

    void setCellule (const int iCellule, const Cellule nouvelleCellule);
    void setCellule (const int iLigne, const int iColonne, const Cellule nouvelleCellule);


    // Position des joueurs
    int positionJoueur (const int iJoueur) const;

    void setPositionJoueur (const int iJoueur, const int nouvellePosition);
    void setPositionJoueur (const int iJoueur, const int nouvelleLigne, const int nouvelleColonne);


    // Actions jouées
    const std::vector<Action>* actionJouees () const;
    std::vector<Action>* actionJouees ();

    void addAction (const Action &nouvelleAction);



private:

    std::array<Cellule, NB_CELLULES> m_cellules;
    std::vector<int> m_positionsJoueurs;
    std::vector<Action> m_actionsJouees;


};

#endif // SITUATIONJEU_H
