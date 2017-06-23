#include "Glouton1Factory.h"

Glouton1Factory::Glouton1Factory ()
{

}

std::shared_ptr<Player> Glouton1Factory::getNewPlayer () const
{
    return std::shared_ptr<Player> (new Glouton1 ());
}
