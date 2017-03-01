#include "Partie.h"

Partie::Partie ()
{

}

const std::vector<Tour>* Partie::tours () const
{
    return &m_tours;
}

Tour* Partie::dernierTour ()
{
    return &m_tours[m_tours.size()-1];
}


void Partie::addTour (const Tour &nouveauTour)
{
    m_tours.push_back(nouveauTour);
}
