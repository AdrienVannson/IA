/*
 * Décrit une action réalisée par un joueur
 */

#ifndef ACTION_HPP
#define ACTION_HPP


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

#endif // ACTION_HPP
