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

    struct Troupe
    {
        bool estBombe; // Sinon, troupe classique
        int nbUnites; // Si c'est une troupe

        int cible; // ID de l'usine que la troupe rejoint
        int nbToursRestants; // Nombre de tours restants avant l'arrivée à l'usine
    };


    // Constructeur
    SituationJeu (const int nbJoueurs = 2);


    // Usines
    const std::vector<Usine>* usines () const;
    void setUsines (const std::vector<Usine> &nouvellesUsines);

    const std::vector< std::vector<int> >* distances () const;
    void setDistances (const std::vector< std::vector<int> > nouvellesDistances);


    // Troupes
    const std::vector<Troupe>* troupes () const;
    std::vector<Troupe>* troupes ();


    // Actions
    const std::vector<Action>* actions () const;

    void ajouterAction (const Action &nouvelleAction);
    void supprimerLesActions ();


    // Fin de la partie
    bool estFini () const;
    void setEstFini (const bool nouveauEstFini);



private:

    // Plateau
    std::vector<Usine> m_usines;
    std::vector< std::vector<int> > m_distances; // Matrice 2D représentant les distances entre chaque usine


    // Troupes
    std::vector<Troupe> m_troupes;


    // Actions à jouer
    std::vector<Action> m_actions;


    // Fin de la partie
    bool m_estFini;


};

#endif // SITUATIONJEU_H
