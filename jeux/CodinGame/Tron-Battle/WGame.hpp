#ifndef WGAME_HPP
#define WGAME_HPP

#include <QGraphicsSimpleTextItem>
#include <QGraphicsView>
#include <QVBoxLayout>

#include "partie/Game.hpp"
#include "UI/WidgetPartieGeneral.h"


class WGame : public WidgetPartieGeneral
{
    Q_OBJECT

public:
    explicit WGame (QWidget *parent = 0);

    QSize minimumSizeHint() const;


private:

    void afficherGrilleVide ();
    void afficherTourActuel ();


    static const int ZOOM = 25;


    QGraphicsView *m_vue;
    QGraphicsScene *m_scene;


};

#endif // WGAME_HPP
