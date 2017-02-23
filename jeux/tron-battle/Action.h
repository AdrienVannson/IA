/*
 * Ce fichier est inclut automatiquement dans la déclaration de la classe Action
 */

#include "partie/Action.h"

// class Action {

public:

    enum Direction {
        GAUCHE,
        DROITE,
        HAUT,
        BAS
    };


    Direction direction () const;
    void setDirection (const Direction nouvelleDirection);


private:

    Direction m_direction;

// }
