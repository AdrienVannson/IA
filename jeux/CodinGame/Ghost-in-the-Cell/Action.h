/*
 * Décrit une action réalisée par un joueur
 */

#ifndef ACTION_H
#define ACTION_H

#include <array>


class Action
{

public:

    enum Type
    {
        DEPLACEMENT, // info1 = source, info2 = cible, info3 = nbUnitées
        BOMBE, // info1 = source, info2 = cible
        AMELIORATION, // info1 = cible
        ATTENTE
    };


    Action ();

    int idJoueur () const;
    void setIdJoueur (const int nouvelIdJoueur);


    // Type
    Type type () const;
    void setType (const Type nouveauType);

    // Informations
    int information (const int iInformation) const;
    void setInformation (const int nouvelleValeur, const int iInformation);


private:

    // ID du joueur ayant réalisé l'action
    int m_idJoueur;


    // Type
    Type m_type;

    // Informations
    std::array<int, 3> m_informations;

};

#endif // ACTION_H
