#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QApplication>
#include <QDockWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QDebug>
#include <QStatusBar>
#include <QLabel>

#include <cstdlib>

#include "arbitre.hpp"
#include "partie/Partie.hpp"
#include "WPartie.hpp"
#include "WJouerPartie.h"
#include "Manager.hpp"
#include "WManager.hpp"
#include "WApercuJoueur.hpp"
#include "WApercuPartie.hpp"
#include "GameRunner.hpp"
#include "tools/batchrunner/WBatchRunner.hpp"
#include "initialiser.hpp"
#include "partie/Joueur/JoueurFactory.hpp"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow (QWidget *parent = 0);
    ~MainWindow();

    Manager<JoueurFactory>* joueursManager ();
    Manager<Partie>* partiesManager ();
    GameRunner* gameRunner ();


public slots:

    void addGame (const std::shared_ptr<Partie> &game);
    void registerGameOverview (QWidget *apercu);

    void afficherPartie (std::shared_ptr<const Partie> partie);

    // UI
    void afficherAPropos ();

    void ajouterAffichagePartie ();
    void addBatchRunnerDock ();

    void fermerOnglerPartie (int index);
    void updateNbSimulations ();


private:

    QHBoxLayout *m_layout;

    QTabWidget *m_ongletsParties;

    Manager<JoueurFactory> m_joueursManager;
    WManager<JoueurFactory, WApercuJoueur> *m_wJoueursManager;

    Manager<Partie> m_partiesManager;
    WManager<Partie, WApercuPartie> *m_wPartiesManager;

    GameRunner *m_gameRunner;
    QLabel *m_wNbSimulations;

};

#endif // MAINWINDOW_HPP
