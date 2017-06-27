#ifndef ABSTRACTGAMESITUATION_HPP
#define ABSTRACTGAMESITUATION_HPP

#include <algorithm>
#include <array>
#include <limits>


class AbstractGameSituation
{

public:

    static const int NB_MAX_JOUEURS = 4;


    AbstractGameSituation (const int nbJoueurs=2);

    // Nombre de joueurs
    int nbJoueurs () const;

    // Joueur devant jouer le coup suivant
    int iPlayer () const;
    void setIPlayer (const int iPlayer);

    // Fin de la partie
    bool estFini () const;
    int idVainqueur () const;



    // Public members
    int m_iPlayer;
    int m_nbJoueurs;

    bool m_estFini;
    std::array<int, NB_MAX_JOUEURS> m_scores;

};

#endif // ABSTRACTGAMESITUATION_HPP
