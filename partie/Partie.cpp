#include "Partie.hpp"

Partie::Partie ()
{

}


// Tours
vector<Tour>& Partie::tours ()
{
    return m_tours;
}

const vector<Tour>& Partie::tours () const
{
    return m_tours;
}


// Dernier tour
Tour& Partie::dernierTour ()
{
    return m_tours[m_tours.size()-1];
}

const Tour& Partie::dernierTour () const
{
    return m_tours[m_tours.size()-1];
}


void Partie::addTour (const Tour &nouveauTour)
{
    m_tours.push_back(nouveauTour);
}
