#include "ExternalPlayerFactory.hpp"

ExternalPlayerFactory::ExternalPlayerFactory()
{

}

Joueur* ExternalPlayerFactory::creerJoueur () const
{
    return new ExternalPlayer ();
}
