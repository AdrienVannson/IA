/*
 * Décrit la situation du jeu
 */

#ifndef SITUATIONJEU_H
#define SITUATIONJEU_H

#include <vector>


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
    };


    // Constructeur
    SituationJeu (const int nbJoueurs = 2);

    void setUsines (const std::vector<Usine> &nouvellesUsines, const std::vector< std::vector<int> > nouvellesDistances);


private:

    // Usines
    std::vector<Usine> m_usines;
    std::vector< std::vector<int> > m_distances; // Matrice 2D représentant les distances entre chaque usine


};

#endif // SITUATIONJEU_H
