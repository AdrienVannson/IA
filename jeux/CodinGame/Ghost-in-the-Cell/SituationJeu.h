/*
 * Décrit la situation du jeu
 */

#ifndef SITUATIONJEU_H
#define SITUATIONJEU_H

#include <vector>

#include "Action.h"


class SituationJeu
{

public:

    /*
     * Constantes
     */

    static const int ADVERSAIRE = -1;
    static const int NEUTRE = 0;
    static const int MOI = 1;




    struct Usine
    {
        int m_nbUnites;
        int m_production;
        int m_proprietaire;
        int nbToursBloquesRestants; // Si l'usine a reçu une bombe, elle ne peut plus produire pendant 5 tours
    };


    // Constructeur
    SituationJeu (const int nbJoueurs = 2);


    // Usines
    const std::vector<Usine>* usines () const;
    void setUsines (const std::vector<Usine> &nouvellesUsines);

    const std::vector< std::vector<int> >* distances () const;
    void setDistances (const std::vector< std::vector<int> > nouvellesDistances);



    // Actions
    const std::vector<Action>* actions () const;

    void ajouterAction (const Action &nouvelleAction);
    void supprimerLesActions ();



private:

    // Plateau
    std::vector<Usine> m_usines;
    std::vector< std::vector<int> > m_distances; // Matrice 2D représentant les distances entre chaque usine


    // Actions à jouer
    std::vector<Action> m_actions;


};

#endif // SITUATIONJEU_H
