#ifndef WABSTRACTGAME_HPP
#define WABSTRACTGAME_HPP

#include <QWidget>
#include <QTimer>

#include <memory>

#include "partie/Partie.hpp"
#include "EventsManager.hpp"
#include "unused.hpp"


class WAbstractPartie : public QWidget
{
    Q_OBJECT

public:

    explicit WAbstractPartie (QWidget *parent = 0);



public slots:

    void showGame (const std::shared_ptr<const Partie> &partie);
    void tourSuivant ();



protected:

    virtual void afficherPartie (const std::shared_ptr<const Partie> &partie);
    virtual void afficherTourActuel () {}


    std::shared_ptr<const Partie> m_partie;
    int m_iTourActuel;



private:

    // Timer pour passer au tour suivant
    QTimer *m_timer;

};

#endif // WABSTRACTGAME_HPP
