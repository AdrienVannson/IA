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
    SituationJeu situationDepart;
    situationDepart.initialiser(m_players.size());

    shared_ptr<Partie> partie = simulerPartie(situationDepart, m_players);
    emit (simulationDone(partie));
}
