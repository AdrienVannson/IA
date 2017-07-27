#include "ExternalPlayer.hpp"


ExternalPlayer::ExternalPlayer (const std::string &chemin) :
    AbstractExternalPlayer (chemin)
{
}

ExternalPlayer::~ExternalPlayer ()
{
}


Action ExternalPlayer::jouerAction (const InformationsTourJoueur &informations)
{
    std::string data;

    qDebug() << "Nombre de joueurs :" << informations.m_joueurs.size();

    data.append(std::to_string(informations.m_joueurs.size()) + " " + std::to_string(informations.m_idJoueur) + "\n");

    for (unsigned int iJoueur=0; iJoueur<informations.m_joueurs.size(); iJoueur++) {
        data.append( std::to_string(informations.m_joueurs[iJoueur].first.second) + " "
                   + std::to_string(informations.m_joueurs[iJoueur].first.first) + " "
                   + std::to_string(informations.m_joueurs[iJoueur].second.second) + " "
                   + std::to_string(informations.m_joueurs[iJoueur].second.first) + "\n" );
    }

    send(data);

    std::string output = getLine();

    Action action;
    action.setDirection(Action::HAUT);

    if (output == "LEFT") {
        action.setDirection(Action::GAUCHE);
    }
    else if (output == "RIGHT") {
        action.setDirection(Action::DROITE);
    }
    else if (output == "UP") {
        action.setDirection(Action::HAUT);
    }
    else if (output == "DOWN") {
        action.setDirection(Action::BAS);
    }

    return action;
}
