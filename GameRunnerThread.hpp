#ifndef GAMERUNNERTHREAD_HPP
#define GAMERUNNERTHREAD_HPP

#include <QThread>

#include <memory>

#include "partie/Partie.hpp"
#include "partie/simulerPartie.hpp"


class GameRunnerThread : public QThread
{
    Q_OBJECT

public:

    explicit GameRunnerThread (QObject *parent=0);

    void setPlayers (const std::vector< std::shared_ptr<Joueur> > &players);

    void run ();


signals:

    void simulationDone (std::shared_ptr<Partie> partie);


private:

    std::vector< std::shared_ptr<Joueur> > m_players;


};

#endif // GAMERUNNERTHREAD_HPP
