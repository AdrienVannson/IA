#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QApplication>
#include <QDockWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>

#include <cstdlib>

#include "Referee.hpp"
#include "partie/PartieDecrite.h"
#include "WGame.hpp"
#include "WJouerPartie.h"
#include "Manager.hpp"
#include "WManager.hpp"
#include "WApercuJoueur.hpp"
#include "WApercuPartie.hpp"
#include "GameRunner.hpp"
#include "WGameRunner.hpp"

// Simulation d'une partie, TODEL
#include "Joueurs/ExternalPlayer/ExternalPlayerFactory.hpp"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow (QWidget *parent = 0);
    ~MainWindow();


public slots:

    void addGame (const std::shared_ptr<PartieDecrite> &game);

    // UI
    void afficherAPropos ();

    void addGameDock ();


private:

    Manager<Player> m_joueursManager;
    WManager<Player, WApercuJoueur> *m_wJoueursManager;

    Manager<PartieDecrite> m_partiesManager;
    WManager<PartieDecrite, WApercuPartie> *m_wPartiesManager;

    GameRunner m_gameRunner;
    WGameRunner *m_wGameRunner;

};

#endif // MAINWINDOW_HPP
