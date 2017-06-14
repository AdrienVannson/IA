#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QDockWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>

#include <cstdlib>

#include "Simulateur.h"
#include "partie/PartieDecrite.h"
#include "WidgetPartie.h"
#include "WJouerPartie.h"
#include "Manager.hpp"
#include "WManager.hpp"
#include "WApercuJoueur.hpp"
#include "WApercuPartie.hpp"

// Simulation d'une partie, TODEL
#include "Joueurs/Glouton1/Glouton1Factory.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow (QWidget *parent = 0);
    ~MainWindow();



public slots:

    void afficherAPropos ();

    void afficherPartie (const int idPartie);



signals:

    void partieAffichee (Partie* partie);



private:

    Manager<Joueur> m_joueursManager;
    WManager<Joueur, WApercuJoueur> *m_wJoueursManager;

    Manager<PartieDecrite> m_partiesManager;
    WManager<PartieDecrite, WApercuPartie> *m_wPartiesManager;

};

#endif // MAINWINDOW_H
