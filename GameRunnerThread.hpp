#ifndef GAMERUNNERTHREAD_HPP
#define GAMERUNNERTHREAD_HPP

#include <QThread>
#include <QDebug> // TODEL

#include <memory>

#include "partie/Game.hpp"
#include "partie/SimulateurPartie.h"


class GameRunnerThread : public QThread
{
    Q_OBJECT

public:

    explicit GameRunnerThread (QObject *parent=0);

    void setPlayers (const std::vector< std::shared_ptr<Player> > &players);

    void run ();


signals:

    void simulationDone (std::shared_ptr<Game> partie);


private:

    std::vector< std::shared_ptr<Player> > m_players;


};

#endif // GAMERUNNERTHREAD_HPP
