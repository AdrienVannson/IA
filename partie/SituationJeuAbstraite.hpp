#ifndef ABSTRACTGAMESITUATION_HPP
#define ABSTRACTGAMESITUATION_HPP

#include <limits>


class SituationJeuAbstraite
{

public:

    SituationJeuAbstraite (const int nbJoueurs=2);

    int nbJoueurs () const;

    // Joueur devant jouer le coup suivant
    int iPlayer () const;
    void setIPlayer (const int iPlayer);


    // Public members
    int m_iPlayer;
    int m_nbJoueurs;

};

#endif // ABSTRACTGAMESITUATION_HPP
