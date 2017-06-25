#ifndef ABSTRACTGAMESITUATION_HPP
#define ABSTRACTGAMESITUATION_HPP


class AbstractGameSituation
{

public:

    AbstractGameSituation (const int nbJoueurs=2);

    // Nombre de joueurs
    int nbJoueurs () const;

    // Joueur devant jouer le coup suivant
    int iPlayer () const;
    void setIPlayer (const int iPlayer);

    // Fin de la partie
    bool estFini () const;
    int idVainqueur () const;

    void setIdVainqueur (const int idVainqueur);



    // Public members
    int m_iPlayer;
    int m_nbJoueurs;
    int m_idVainqueur;

};

#endif // ABSTRACTGAMESITUATION_HPP
