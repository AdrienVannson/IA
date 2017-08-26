/*
 * Décrit une partie
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "Tour.hpp"


class Partie
{

public:

    Partie ();

    const std::vector<Tour>* tours () const;
    Tour* dernierTour ();
    Tour lastTurn () const;

    void addTour (const Tour &nouveauTour);


private:
    std::vector<Tour> m_tours;

};

#endif // GAME_HPP
