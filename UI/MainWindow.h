#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QDockWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>

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


private:

    JoueurManager m_joueurManager;

};

#endif // MAINWINDOW_H
