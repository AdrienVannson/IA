/*
 * Décrit une partie
 */

#ifndef PARTIE_H
#define PARTIE_H

#include <vector>

#include "Tour.h"


class Partie
{

public:
    Partie ();

    const std::vector<Tour>* tours () const;
    Tour* dernierTour ();

    void addTour (const Tour &nouveauTour);


private:
    std::vector<Tour> m_tours;

};

#endif // PARTIE_H
