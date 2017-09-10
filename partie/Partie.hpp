#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "Tour.hpp"


class Partie
{

public:

    Partie ();

    std::vector<Tour>& tours ();
    const std::vector<Tour>& tours () const;

    Tour& dernierTour ();
    const Tour& dernierTour () const;

    void addTour (const Tour &nouveauTour);


private:
    std::vector<Tour> m_tours;

};

#endif // GAME_HPP
