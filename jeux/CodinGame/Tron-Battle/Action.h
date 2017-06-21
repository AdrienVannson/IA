/*
 * Décrit une action réalisée par un joueur
 */

#ifndef ACTION_H
#define ACTION_H


class Action
{

public:

    Action ();


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

};

#endif // ACTION_H
