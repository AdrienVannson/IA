#include "GameRunner.hpp"

GameRunner::GameRunner () :
    m_estPartieEnCours (false),
    m_callbackFinPartie (0)
{
    qRegisterMetaType< std::shared_ptr<Partie> >("std::shared_ptr<Partie>");
}

void GameRunner::runGame (std::vector< std::shared_ptr<Joueur> > &players, CallbackFinSimulation *callback)
{
    m_enAttente.push( std::make_pair(players, callback) );
    runPendingGames();

    emit updated();
}

int GameRunner::nbPendingGames () const
{
    return m_enAttente.size();
}

void GameRunner::handleResults (std::shared_ptr<Partie> partie)
{
    emit gameRunned(partie);

    (*m_callbackFinPartie) (partie);
    delete m_callbackFinPartie;

    m_estPartieEnCours = false;
    runPendingGames();
}

void GameRunner::runPendingGames ()
{
    if (m_estPartieEnCours || m_enAttente.empty()) {
        return;
    }

    m_estPartieEnCours = true;

    std::vector<std::shared_ptr<Joueur>> joueurs = m_enAttente.front().first;
    m_callbackFinPartie = m_enAttente.front().second;
    m_enAttente.pop();

    emit updated();

    GameRunnerThread *gameRunnerThread = new GameRunnerThread (this);
    gameRunnerThread->setPlayers(joueurs);
    connect(gameRunnerThread, &GameRunnerThread::simulationDone, this, &GameRunner::handleResults);
    connect(gameRunnerThread, &GameRunnerThread::finished, gameRunnerThread, &QObject::deleteLater);
    gameRunnerThread->start();
}
