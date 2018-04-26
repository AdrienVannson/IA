#ifndef WAPERCUJOUEUR_HPP
#define WAPERCUJOUEUR_HPP

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include <memory>

#include "partie/Joueur/JoueurFactory.hpp"

using namespace std;


class WApercuJoueur : public QWidget
{
    Q_OBJECT

public:

    explicit WApercuJoueur (QWidget *parent=0);

    void setObject (const shared_ptr<const JoueurFactory> &joueur);


private:

    shared_ptr<const JoueurFactory> m_joueur;

    QPushButton *m_bouton;


};

#endif // WAPERCUJOUEUR_HPP
