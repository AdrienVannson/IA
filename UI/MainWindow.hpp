#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <utility>
#include <functional>

#include <QApplication>
#include <QDockWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QMessageBox>
#include <QTabWidget>
#include <QStatusBar>
#include <QLabel>

#include "Partie.hpp"
#include "UI/WPartie.hpp"
#include "WJouerPartie.h"
#include "Manager.hpp"
#include "WManager.hpp"
#include "WApercuJoueur.hpp"
#include "WApercuPartie.hpp"
#include "GameRunner.hpp"
#include "tools/batchrunner/WBatchRunner.hpp"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow (QWidget *parent = 0);
    ~MainWindow();

    Manager< std::pair< std::function<Joueur*()>, QString> >* joueursManager ();
    Manager<Partie>* partiesManager ();
    GameRunner* gameRunner ();


public slots:
    void addGame (const shared_ptr<Partie> &game);
    void registerGameOverview (QWidget *apercu);

    void afficherPartie (shared_ptr<const Partie> partie);

    // UI
    void addDock (QWidget *widget, const QString &nom);

    void afficherAPropos ();

    void fermerOnglerPartie (int index);
    void updateNbSimulations ();


private:
    QTabWidget *m_ongletsParties;

    Manager< std::pair< std::function<Joueur*()>, QString> > m_joueursManager;
    WManager< std::pair< std::function<Joueur*()>, QString>, WApercuJoueur> *m_wJoueursManager;

    Manager<Partie> m_partiesManager;
    WManager<Partie, WApercuPartie> *m_wPartiesManager;

    GameRunner *m_gameRunner;
    QLabel *m_wNbSimulations;

};

#endif // MAINWINDOW_HPP
