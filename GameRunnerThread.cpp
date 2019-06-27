#include "GameRunnerThread.hpp"

GameRunnerThread::GameRunnerThread (QObject *parent) :
    QThread (parent)
{
}

void GameRunnerThread::setPlayers (const vector<shared_ptr<Joueur>> &players)
{
    m_players = players;
}

void GameRunnerThread::run ()
{
    shared_ptr<Partie> partie = simulerPartie(m_players);
    emit (simulationDone(partie));
}
