#ifndef SITUATIONJEUGENERALE_H
#define SITUATIONJEUGENERALE_H


class SituationJeuGenerale
{

public:

    SituationJeuGenerale (const int nbJoueurs=2);

    // Nombre de joueurs
    int nbJoueurs () const;

    // Fin de la partie
    bool estFini () const;
    int idVainqueur () const;

    void setIdVainqueur (const int idVainqueur);


private:

    int m_nbJoueurs;
    int m_idVainqueur;


};

#endif // SITUATIONJEUGENERALE_H
