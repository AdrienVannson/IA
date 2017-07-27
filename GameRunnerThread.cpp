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

    GameSituation situationDepart;
    situationDepart.init();

    Game *partie = SimulateurPartie::simulerPartie(situationDepart, m_players);

    for (std::shared_ptr<Player> &player : m_players) {
        player->endGame();
    }

    emit (simulationDone( std::shared_ptr<Game>(partie) ));
}
