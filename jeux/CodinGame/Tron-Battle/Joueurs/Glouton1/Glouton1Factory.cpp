#include "Glouton1Factory.h"

Glouton1Factory::Glouton1Factory ()
{

}

Joueur* Glouton1Factory::creerJoueur () const
{
    return new Glouton1 ();
}
