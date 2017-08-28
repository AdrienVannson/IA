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
    SituationJeu situationDepart;
    situationDepart.initialiser(m_players.size());

    Partie *partie = SimulateurPartie::simulerPartie(situationDepart, m_players);

    emit (simulationDone( std::shared_ptr<Partie>(partie) ));
}
