#ifndef PARTIE_HPP
#define PARTIE_HPP

#include <vector>

#include "Tour.hpp"

using namespace std;


class Partie
{

public:

    Partie ();

    vector<Tour>& tours ();
    const vector<Tour>& tours () const;

    Tour& dernierTour ();
    const Tour& dernierTour () const;

    void addTour (const Tour &nouveauTour);


private:
    vector<Tour> m_tours;

};

#endif // PARTIE_HPP
