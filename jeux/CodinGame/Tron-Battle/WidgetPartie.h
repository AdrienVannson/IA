#ifndef WIDGETPARTIE_H
#define WIDGETPARTIE_H

#include <QGraphicsSimpleTextItem>
#include <QGraphicsView>
#include <QTimer>

#include "partie/Partie.h"


class WidgetPartie : public QGraphicsView
{
    Q_OBJECT

public:
    explicit WidgetPartie (QWidget *parent = 0);

    QSize minimumSizeHint() const;


    void afficherPartie (const Partie *partie);


public slots:

    void tourSuivant ();



private:

    void afficherGrilleVide ();
    void afficherTourActuel ();

    void afficherTour (const int iTour);


    static const int ZOOM = 25;


    QGraphicsScene *m_scene;

    Partie m_partie;
    int m_iTourActuel;


    // Timer pour passer au tour suivant
    QTimer *m_timer;

};

#endif // WIDGETPARTIE_H
