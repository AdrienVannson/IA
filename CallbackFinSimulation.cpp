#include "CallbackFinSimulation.hpp"

CallbackFinSimulation::CallbackFinSimulation ()
{}

CallbackFinSimulation::~CallbackFinSimulation ()
{}

void CallbackFinSimulation::operator() (const shared_ptr<Partie> &partie)
{
    UNUSED(partie);
}
