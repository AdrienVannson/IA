#include "GameRunnerThread.hpp"

GameRunnerThread::GameRunnerThread (QObject *parent) :
    QThread (parent)
{
}

void GameRunnerThread::setPlayers (const std::vector< std::shared_ptr<Joueur> > &players)
{
    m_players = players;
}

void GameRunnerThread::run ()
{
    for (std::shared_ptr<Joueur> &player : m_players) {
        player->startGame();
    }

    SituationJeu situationDepart (m_players.size());
    situationDepart.init();

    Partie *partie = SimulateurPartie::simulerPartie(situationDepart, m_players);

    for (std::shared_ptr<Joueur> &player : m_players) {
        player->endGame();
    }

    emit (simulationDone( std::shared_ptr<Partie>(partie) ));
}
