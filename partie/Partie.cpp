#include "Partie.h"

Partie::Partie ()
{

}

const std::vector<Tour>* Partie::tours () const
{
    return &m_tours;
}

void Partie::addTour (const Tour &nouveauTour)
{
    m_tours.push_back(nouveauTour);
}
