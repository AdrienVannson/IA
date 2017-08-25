#ifndef WABSTRACTGAME_HPP
#define WABSTRACTGAME_HPP

#include <QWidget>
#include <QTimer>

#include <memory>

#include "partie/DescribedGame.hpp"
#include "EventsManager.hpp"


class WAbstractPartie : public QWidget
{
    Q_OBJECT

public:

    explicit WAbstractPartie (QWidget *parent = 0);



public slots:

    void showGame (const std::shared_ptr<const DescribedGame> &partie);
    void tourSuivant ();



protected:

    virtual void afficherTourActuel () = 0;


    Game m_partie;
    int m_iTourActuel;



private:

    // Timer pour passer au tour suivant
    QTimer *m_timer;

};

#endif // WABSTRACTGAME_HPP
