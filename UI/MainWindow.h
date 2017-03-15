#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QDockWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>

#include "Simulateur.h"
#include "partie/JoueursManager.h"
#include "partie/PartiesManager.h"
#include "partie/Partie.h"
#include "WidgetPartie.h"
#include "PartiesManagerWidget.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow (QWidget *parent = 0);
    ~MainWindow();


private:

    PartiesManager m_partiesManager;
    PartiesManagerWidget *m_partiesManagerWidget;

    JoueursManager m_joueursManager;

};

#endif // MAINWINDOW_H
