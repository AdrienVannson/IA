#ifndef AFFICHAGESIMULATEUR_HPP
#define AFFICHAGESIMULATEUR_HPP

#include <QGraphicsView>

#include "Partie.hpp"
#include "SceneSimulateur.hpp"


class AffichageSimulateur : public QGraphicsView
{
    Q_OBJECT

public:
    AffichageSimulateur (QWidget *parent = 0);

    void afficherPartie (const Partie &partie);


private:
    SceneSimulateur *m_scene;

};

#endif // AFFICHAGESIMULATEUR_HPP
