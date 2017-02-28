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

    static const int NEUTRE = -1;




    struct Usine
    {
        int m_nbUnites;
        int m_production;
        int m_proprietaire;
        int m_nbToursBloquesRestants; // Si l'usine a reçu une bombe, elle ne peut plus produire pendant 5 tours
    };

    struct Troupe
    {
        Troupe () :
            m_estBombe (false)
        {}

        bool m_estBombe; // Sinon, troupe classique
        int m_nbUnites; // Si c'est une troupe
        int m_idJoueur; // Si c'est une troupe

        int m_cible; // ID de l'usine que la troupe rejoint
        int m_nbToursRestants; // Nombre de tours restants avant l'arrivée à l'usine
    };


    // Constructeur
    SituationJeu (const int nbJoueurs = 2);


    // Nombre de tours écoulés
    int nbToursEcoules () const;
    void incrementerNbToursEcoules ();


    // Usines
    std::vector<Usine>* usines ();
    const std::vector<Usine>* usines () const;
    void setUsines (const std::vector<Usine> &nouvellesUsines);

    const std::vector< std::vector<int> >* distances () const;
    int distance (const int usineA, const int usineB) const;

    void setDistances (const std::vector< std::vector<int> > nouvellesDistances);


    // Troupes
    const std::vector<Troupe>* troupes () const;
    std::vector<Troupe>* troupes ();

    void addTroupe (const Troupe &nouvelleTroupe);


    // Bombes restantes
    int nbBombesRestantes (const int idJoueur) const;
    void utiliserBombe (const int idJoueur);


    // Actions
    const std::vector<Action>* actions () const;

    void addAction (const Action &nouvelleAction);
    void supprimerLesActions ();


    // Fin de la partie
    bool estFini () const;

    int idVainqueur () const;
    void setIdVainqueur (const int nouvelIdVainqueur);



private:

    // Nombre de tours écoulés
    int m_nbToursEcoules;


    // Plateau
    std::vector<Usine> m_usines;
    std::vector< std::vector<int> > m_distances; // Matrice 2D représentant les distances entre chaque usine


    // Troupes
    std::vector<Troupe> m_troupes;


    // Bombes restantes par joueur
    std::vector<int> m_nbBombesRestantes;



    // Actions à jouer
    std::vector<Action> m_actions;


    // Fin de la partie
    int m_idVainqueur; // -1 si la partie n'est pas terminée, l'ID du joueur sinon


};

#endif // SITUATIONJEU_H
