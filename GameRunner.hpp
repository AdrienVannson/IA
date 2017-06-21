#ifndef GAMERUNNER_HPP
#define GAMERUNNER_HPP

#include <QObject>

#include <vector>
#include <memory>
#include <queue>

#include "partie/SimulateurPartie.h"
#include "partie/PartieDecrite.h"
#include "partie/Joueur/Player.hpp"
#include "GameRunnerThread.hpp"


class GameRunner : public QObject
{
    Q_OBJECT


public:

    GameRunner ();

    void runGame (std::vector< std::shared_ptr<Player> > &players);


public slots:

    void handleResults (std::shared_ptr<Game> partie);


signals:

    void gameRunned (std::shared_ptr<PartieDecrite> game);


private:

    void runPendingGames ();

    bool m_isGamePlaying;
    std::queue< std::vector<std::shared_ptr<Player>> > m_pendingGames;


};

#endif // GAMERUNNER_HPP
