#ifndef ACTIONGENERALE_H
#define ACTIONGENERALE_H


class ActionGenerale
{

public:
    ActionGenerale ();

    int idJoueur () const;
    void setIdJoueur (const int nouvelIdJoueur);


private:

    // ID du joueur ayant réalisé l'action
    int m_idJoueur;

};

#endif // ACTIONGENERALE_H
