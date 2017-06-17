#include "ExternalPlayer.hpp"

ExternalPlayer::ExternalPlayer ()
{

}

ExternalPlayer::~ExternalPlayer ()
{
}


Joueur* ExternalPlayer::clone () const
{
    return new ExternalPlayer (*this);
}

Action ExternalPlayer::jouerAction (const InformationsTourJoueur &informations)
{
    Action action;
    action.setDirection(Action::DROITE);
    return action;
}
