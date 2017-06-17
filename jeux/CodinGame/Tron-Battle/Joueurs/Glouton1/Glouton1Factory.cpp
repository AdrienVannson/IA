#include "Glouton1Factory.h"

Glouton1Factory::Glouton1Factory ()
{

}

Player* Glouton1Factory::creerJoueur () const
{
    return new Glouton1 ();
}
