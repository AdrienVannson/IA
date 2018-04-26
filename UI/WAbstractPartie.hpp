#ifndef WABSTRACTGAME_HPP
#define WABSTRACTGAME_HPP

#include <QWidget>
#include <QTimer>

#include <memory>

#include "partie/Partie.hpp"
#include "unused.hpp"

using namespace std;


class WAbstractPartie : public QWidget
{
    Q_OBJECT

public:

    explicit WAbstractPartie (QWidget *parent = 0);



public slots:

    void showGame (const shared_ptr<const Partie> &partie);
    void tourSuivant ();



protected:

    virtual void afficherPartie (const shared_ptr<const Partie> &partie);
    virtual void afficherTourActuel () {}


    shared_ptr<const Partie> m_partie;
    int m_iTourActuel;



private:

    // Timer pour passer au tour suivant
    QTimer *m_timer;

};

#endif // WABSTRACTGAME_HPP
