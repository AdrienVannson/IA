#ifndef GAMERUNNERTHREAD_HPP
#define GAMERUNNERTHREAD_HPP

#include <QThread>

#include <memory>

#include "partie/Partie.hpp"
#include "partie/simulerPartie.hpp"

using namespace std;


class GameRunnerThread : public QThread
{
    Q_OBJECT

public:

    explicit GameRunnerThread (QObject *parent=0);

    void setPlayers (const vector<shared_ptr<Joueur>> &players);

    void run ();


signals:

    void simulationDone (shared_ptr<Partie> partie);


private:

    vector<shared_ptr<Joueur>> m_players;


};

#endif // GAMERUNNERTHREAD_HPP
