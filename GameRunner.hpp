#ifndef GAMERUNNER_HPP
#define GAMERUNNER_HPP

#include <QObject>

#include <vector>
#include <memory>
#include <queue>

#include "partie/SimulateurPartie.h"
#include "partie/PartieDecrite.hpp"
#include "partie/Joueur/Joueur.hpp"
#include "GameRunnerThread.hpp"


class GameRunner : public QObject
{
    Q_OBJECT


public:

    GameRunner ();

    void runGame (std::vector< std::shared_ptr<Joueur> > &players);

    int nbPendingGames () const;


public slots:

    void handleResults (std::shared_ptr<Partie> partie);


signals:

    void updated (); // Emit each time a game is added or finished
    void gameRunned (std::shared_ptr<PartieDecrite> game);


private:

    void runPendingGames ();

    bool m_isGamePlaying;
    std::queue< std::vector<std::shared_ptr<Joueur>> > m_pendingGames;


};

#endif // GAMERUNNER_HPP
