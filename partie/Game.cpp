#include "Game.hpp"

Game::Game ()
{

}

const std::vector<Tour>* Game::tours () const
{
    return &m_tours;
}

Tour* Game::dernierTour ()
{
    return &m_tours[m_tours.size()-1];
}


void Game::addTour (const Tour &nouveauTour)
{
    m_tours.push_back(nouveauTour);
}
