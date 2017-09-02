#ifndef GAMERUNNER_HPP
#define GAMERUNNER_HPP

#include <QObject>

#include <memory>
#include <queue>
#include <utility>
#include <vector>

#include "partie/simulerPartie.hpp"
#include "partie/Partie.hpp"
#include "partie/Joueur/Joueur.hpp"
#include "GameRunnerThread.hpp"
#include "unused.hpp"


void callbackVide (std::shared_ptr<Partie> partie);


class GameRunner : public QObject
{
    Q_OBJECT


public:

    GameRunner ();

    void runGame ( std::vector< std::shared_ptr<Joueur> > &players,
                   void (*callback) (std::shared_ptr<Partie>)=callbackVide
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
    std::queue< std::pair<std::vector<std::shared_ptr<Joueur>>, void (*)(std::shared_ptr<Partie>)> > m_enAttente;
    void (*m_callbackFinPartie) (std::shared_ptr<Partie>);


};

#endif // GAMERUNNER_HPP
