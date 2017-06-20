#include "GameRunner.hpp"

GameRunner::GameRunner() :
    m_isGamePlaying (false)
{
    qRegisterMetaType< std::shared_ptr<Partie> >("std::shared_ptr<Partie>");
}

void GameRunner::runGame (std::vector< std::shared_ptr<Player> > &players)
{
    m_pendingGames.push(players);
    runPendingGames();
}

void GameRunner::handleResults (std::shared_ptr<Partie> partie)
{
    std::shared_ptr<PartieDecrite> partieDecrite (new PartieDecrite(*partie.get()));
    emit gameRunned(partieDecrite);

    m_isGamePlaying = false;
    runPendingGames();
}

void GameRunner::runPendingGames ()
{
    if (m_isGamePlaying || m_pendingGames.empty()) {
        return;
    }

    m_isGamePlaying = true;

    std::vector<std::shared_ptr<Player>> players = m_pendingGames.front();
    m_pendingGames.pop();

    GameRunnerThread *gameRunnerThread = new GameRunnerThread (this);
    gameRunnerThread->setPlayers(players);
    connect(gameRunnerThread, &GameRunnerThread::simulationDone, this, &GameRunner::handleResults);
    connect(gameRunnerThread, &GameRunnerThread::finished, gameRunnerThread, &QObject::deleteLater);
    gameRunnerThread->start();
}
