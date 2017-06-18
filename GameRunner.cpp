#include "GameRunner.hpp"

GameRunner::GameRunner()
{
}

void GameRunner::runGame (std::vector< std::shared_ptr<Player> > &players)
{
    qRegisterMetaType< std::shared_ptr<Partie> >("std::shared_ptr<Partie>");

    GameRunnerThread *gameRunnerThread = new GameRunnerThread (this);
    gameRunnerThread->setPlayers(players);
    connect(gameRunnerThread, &GameRunnerThread::simulationDone, this, &GameRunner::handleResults);
    connect(gameRunnerThread, &GameRunnerThread::finished, gameRunnerThread, &QObject::deleteLater);
    gameRunnerThread->start();
}

void GameRunner::handleResults (std::shared_ptr<Partie> partie)
{
    std::shared_ptr<PartieDecrite> partieDecrite (new PartieDecrite(*partie.get()));
    emit gameRunned(partieDecrite);
}
