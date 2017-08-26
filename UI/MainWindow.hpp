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
#include "partie/PartieDecrite.hpp"
#include "WPartie.hpp"
#include "WJouerPartie.h"
#include "Manager.hpp"
#include "WManager.hpp"
#include "WApercuJoueur.hpp"
#include "WApercuPartie.hpp"
#include "GameRunner.hpp"
#include "WGameRunner.hpp"
#include "tools/batchrunner/WBatchRunner.hpp"
#include "EventsManager.hpp"
#include "initialiser.hpp"
#include "partie/Joueur/JoueurFactory.hpp"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow (QWidget *parent = 0);
    ~MainWindow();

    Manager<JoueurFactory>* joueursManager ();
    Manager<PartieDecrite>* partiesManager ();
    GameRunner* gameRunner ();


public slots:

    void addGame (const std::shared_ptr<PartieDecrite> &game);
    void registerGameOverview (QWidget *apercu);

    // UI
    void afficherAPropos ();

    void addGameDock ();
    void addGameRunnerDock ();
    void addBatchRunnerDock ();


private:

    Manager<JoueurFactory> m_joueursManager;
    WManager<JoueurFactory, WApercuJoueur> *m_wJoueursManager;

    Manager<PartieDecrite> m_partiesManager;
    WManager<PartieDecrite, WApercuPartie> *m_wPartiesManager;

    EventsManager m_eventsManager;
    GameRunner m_gameRunner;

};

#endif // MAINWINDOW_HPP
