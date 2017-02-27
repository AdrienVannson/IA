#ifndef WIDGETPARTIE_H
#define WIDGETPARTIE_H

#include <QTimer>
#include <QWidget>

#include "partie/Partie.h"


class WidgetPartie : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetPartie (QWidget *parent = 0);

    // QSize minimumSizeHint() const;


    void afficherPartie (const Partie *partie);


public slots:

    void tourSuivant ();



private:

    void afficherTourActuel ();

    void afficherTour (const int iTour);


    const Partie *m_partie;
    int m_iTourActuel;


    // Timer pour passer au tour suivant
    QTimer *m_timer;

};

#endif // WIDGETPARTIE_H
