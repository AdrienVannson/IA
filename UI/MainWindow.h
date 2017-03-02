#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QDebug>
#include <QDockWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>
#include <QTimer>

#include "JoueurNaif.h"
#include "Simulateur.h"
#include "partie/JoueurManager.h"
#include "partie/Partie.h"
#include "WidgetPartie.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow (QWidget *parent = 0);
    ~MainWindow();


public slots:
    void entrainerJoueur ();


private:
    QTimer *m_timerEntrainement;

    JoueurManager m_joueurManager;


};

#endif // MAINWINDOW_H
