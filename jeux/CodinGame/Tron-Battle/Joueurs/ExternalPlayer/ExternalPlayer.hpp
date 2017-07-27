#ifndef EXTERNALPLAYER_HPP
#define EXTERNALPLAYER_HPP

#include <QDebug>

#include "players/AbstractExternalPlayer.hpp"


class ExternalPlayer : public AbstractExternalPlayer
{

public:

    ExternalPlayer (const std::string &chemin="");
    ~ExternalPlayer ();

    Action jouerAction (const InformationsTourJoueur &informations);

};

#endif // EXTERNALPLAYER_HPP
