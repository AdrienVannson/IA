#ifndef SITUATIONJEUGENERALE_H
#define SITUATIONJEUGENERALE_H


class SituationJeuGenerale
{

public:

    SituationJeuGenerale (const int nbJoueurs=2);

    // Nombre de joueurs
    int nbJoueurs () const;

    // Joueur devant jouer le coup suivant
    int iPlayer () const;
    void setIPlayer (const int iPlayer);

    // Fin de la partie
    bool estFini () const;
    int idVainqueur () const;

    void setIdVainqueur (const int idVainqueur);


private:

    int m_iPlayer;
    int m_nbJoueurs;
    int m_idVainqueur;


};

#endif // SITUATIONJEUGENERALE_H
