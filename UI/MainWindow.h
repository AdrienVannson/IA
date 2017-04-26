#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QDockWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>

#include <cstdlib>

#include "Simulateur.h"
#include "partie/JoueursManager.h"
#include "partie/PartiesManager.h"
#include "partie/Partie.h"
#include "WidgetPartie.h"
#include "PartiesManagerWidget.h"
#include "JoueursManagerWidget.h"

// Simulation d'une partie, TODEL
#include "Joueurs/Glouton1/Glouton1Factory.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow (QWidget *parent = 0);
    ~MainWindow();



public slots:

    void afficherPartie (const int idPartie);



signals:

    void partieAffichee (Partie* partie);



private:

    JoueursManager m_joueursManager;
    JoueursManagerWidget *m_joueursManagerWidget;

    PartiesManager m_partiesManager;
    PartiesManagerWidget *m_partiesManagerWidget;

};

#endif // MAINWINDOW_H
