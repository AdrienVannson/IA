#ifndef ABSTRACTGAMESITUATION_HPP
#define ABSTRACTGAMESITUATION_HPP

#include <limits>


class SituationJeuAbstraite
{

public:

    SituationJeuAbstraite ();

    // Joueur devant jouer le coup suivant
    int iPlayer () const;
    void setIPlayer (const int iPlayer);


    // Public members
    int m_iPlayer;

};

#endif // ABSTRACTGAMESITUATION_HPP
