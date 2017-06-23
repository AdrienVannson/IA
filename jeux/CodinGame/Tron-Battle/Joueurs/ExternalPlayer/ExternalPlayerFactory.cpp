#include "ExternalPlayerFactory.hpp"

ExternalPlayerFactory::ExternalPlayerFactory()
{

}

std::shared_ptr<Player> ExternalPlayerFactory::getNewPlayer () const
{
    return std::shared_ptr<Player> (new ExternalPlayer ());
}
