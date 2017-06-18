#ifndef GAMERUNNER_HPP
#define GAMERUNNER_HPP

#include <QObject>

#include <vector>
#include <memory>

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

    void handleResults (std::shared_ptr<Partie> partie);


signals:

    void gameRunned (std::shared_ptr<PartieDecrite> game);


};

#endif // GAMERUNNER_HPP
