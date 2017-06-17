#include "ExternalPlayerFactory.hpp"

ExternalPlayerFactory::ExternalPlayerFactory()
{

}

Player* ExternalPlayerFactory::creerJoueur () const
{
    return new ExternalPlayer ();
}
