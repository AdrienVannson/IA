#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QApplication>
#include <QDockWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>

#include <cstdlib>

#include "Arbitre.hpp"
#include "partie/DescribedGame.hpp.h"
#include "WGame.hpp"
#include "WJouerPartie.h"
#include "Manager.hpp"
#include "WManager.hpp"
#include "WApercuJoueur.hpp"
#include "WApercuPartie.hpp"
#include "GameRunner.hpp"
#include "WGameRunner.hpp"
#include "tools/batchrunner/WBatchRunner.hpp"
#include "EventsManager.hpp"

// Simulation d'une partie, TODEL
#include "Joueurs/ExternalPlayer/ExternalPlayerFactory.hpp"
#include "Joueurs/Glouton1/Glouton1Factory.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow (QWidget *parent = 0);
    ~MainWindow();


public slots:

    void addGame (const std::shared_ptr<DescribedGame> &game);
    void registerGameOverview (QWidget *apercu);

    // UI
    void afficherAPropos ();

    void addGameDock ();
    void addGameRunnerDock ();
    void addBatchRunnerDock ();


private:

    Manager<Player> m_joueursManager;
    WManager<Player, WApercuJoueur> *m_wJoueursManager;

    Manager<DescribedGame> m_partiesManager;
    WManager<DescribedGame, WApercuPartie> *m_wPartiesManager;

    EventsManager m_eventsManager;
    GameRunner m_gameRunner;

};

#endif // MAINWINDOW_HPP
