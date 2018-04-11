#ifndef GAMERUNNER_HPP
#define GAMERUNNER_HPP

#include <QObject>

#include <memory>
#include <queue>
#include <utility>
#include <vector>

#include "CallbackFinSimulation.hpp"
#include "partie/simulerPartie.hpp"
#include "partie/Partie.hpp"
#include "partie/Joueur/Joueur.hpp"
#include "GameRunnerThread.hpp"
#include "unused.hpp"

using namespace std;


class GameRunner : public QObject
{
    Q_OBJECT


public:

    GameRunner (QObject *parent=0);

    void runGame ( std::vector< std::shared_ptr<Joueur> > &players,
                   CallbackFinSimulation *callback=new CallbackFinSimulation()
    );

    int nbPendingGames () const;


public slots:

    void handleResults (std::shared_ptr<Partie> partie);


signals:

    void updated (); // Emit each time a game is added or finished
    void gameRunned (std::shared_ptr<Partie> game);


private:

    void runPendingGames ();

    bool m_estPartieEnCours;
    std::queue< std::pair<std::vector<std::shared_ptr<Joueur>>, CallbackFinSimulation*> > m_enAttente;
    CallbackFinSimulation* m_callbackFinPartie;


};

#endif // GAMERUNNER_HPP
