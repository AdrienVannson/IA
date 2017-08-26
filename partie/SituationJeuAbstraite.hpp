#ifndef ABSTRACTGAMESITUATION_HPP
#define ABSTRACTGAMESITUATION_HPP

#include <algorithm>
#include <limits>
#include <vector>


class SituationJeuAbstraite
{

public:

    SituationJeuAbstraite (const int nbJoueurs=2);

    int nbJoueurs () const;

    // Joueur devant jouer le coup suivant
    int iPlayer () const;
    void setIPlayer (const int iPlayer);

    // Fin de la partie
    bool estFini () const;
    int idVainqueur () const;



    // Public members
    int m_iPlayer;

    bool m_estFini;
    std::vector<int> m_scores;

};

#endif // ABSTRACTGAMESITUATION_HPP
