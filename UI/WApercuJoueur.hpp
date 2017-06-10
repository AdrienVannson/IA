#ifndef WAPERCUJOUEUR_HPP
#define WAPERCUJOUEUR_HPP

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include "partie/Joueur/Joueur.h"


class WApercuJoueur : public QWidget
{
    Q_OBJECT

public:

    explicit WApercuJoueur (QWidget *parent=0);

    void setObjet (const Joueur *joueur);


private:

    const Joueur *m_joueur;

    QPushButton *m_bouton;


};

#endif // WAPERCUJOUEUR_HPP
