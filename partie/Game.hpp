/*
 * Décrit une partie
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "Tour.h"


class Game
{

public:

    Game ();

    const std::vector<Tour>* tours () const;
    Tour* dernierTour ();

    void addTour (const Tour &nouveauTour);


private:
    std::vector<Tour> m_tours;

};

#endif // GAME_HPP
