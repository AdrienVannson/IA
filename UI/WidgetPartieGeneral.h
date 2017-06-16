#ifndef WIDGETPARTIEGENERAL_H
#define WIDGETPARTIEGENERAL_H

#include <QWidget>
#include <QTimer>

#include <memory>

#include "partie/PartieDecrite.h"
#include "EventsManager.hpp"


class WidgetPartieGeneral : public QWidget
{
    Q_OBJECT

public:

    explicit WidgetPartieGeneral (QWidget *parent = 0);



public slots:

    void showGame (const std::shared_ptr<const PartieDecrite> &partie);
    void tourSuivant ();



protected:

    virtual void afficherTourActuel () = 0;


    Partie m_partie;
    int m_iTourActuel;



private:

    // Timer pour passer au tour suivant
    QTimer *m_timer;

};

#endif // WIDGETPARTIEGENERAL_H
