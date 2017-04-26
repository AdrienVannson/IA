#ifndef WIDGETPARTIE_H
#define WIDGETPARTIE_H

#include <QGraphicsSimpleTextItem>
#include <QGraphicsView>
#include <QVBoxLayout>

#include "partie/Partie.h"
#include "UI/WidgetPartieGeneral.h"


class WidgetPartie : public WidgetPartieGeneral
{
    Q_OBJECT

public:
    explicit WidgetPartie (QWidget *parent = 0);

    QSize minimumSizeHint() const;


private:

    void afficherGrilleVide ();
    void afficherTourActuel ();


    static const int ZOOM = 25;


    QGraphicsView *m_vue;
    QGraphicsScene *m_scene;


};

#endif // WIDGETPARTIE_H
