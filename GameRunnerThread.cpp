#include "GameRunnerThread.hpp"

GameRunnerThread::GameRunnerThread (QObject *parent) :
    QThread (parent)
{
}

void GameRunnerThread::setPlayers (const std::vector< std::shared_ptr<Player> > &players)
{
    m_players = players;
}

void GameRunnerThread::run ()
{
    for (std::shared_ptr<Player> &player : m_players) {
        player->startGame();
    }


    SituationJeu situationDepart (m_players.size());

    for (unsigned int iPlayer=0; iPlayer<m_players.size(); iPlayer++) {
        situationDepart.setPositionJoueur(iPlayer, rand()%(SituationJeu::NB_CELLULES));
    }


    Partie *partie = SimulateurPartie::simulerPartie(situationDepart, m_players);


    for (std::shared_ptr<Player> &player : m_players) {
        player->endGame();
    }

    emit (simulationDone( std::shared_ptr<Partie>(partie) ));
}
