#ifndef SCENESIMULATEUR_H
#define SCENESIMULATEUR_H

#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QPropertyAnimation>
#include <QTimer>

#include <vector>

#include "Partie.hpp"


class SceneSimulateur : public QGraphicsScene
{
    Q_OBJECT

public:
    SceneSimulateur ();

    void afficherPartie (const Partie &partie);


public slots:
    void tourSuivant ();


private:
    QTimer *m_timer;

    Partie m_partie;

    int m_iTour;

    QGraphicsSimpleTextItem *m_affichageNbTours;


    static const int m_TEMPS_AFFICHAGE_TOUR = 100;

};

#endif // SCENESIMULATEUR_H
