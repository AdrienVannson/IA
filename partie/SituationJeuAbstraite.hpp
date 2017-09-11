#ifndef SITUATIONJEUABSTRAITE_HPP
#define SITUATIONJEUABSTRAITE_HPP


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

#endif // SITUATIONJEUABSTRAITE_HPP
