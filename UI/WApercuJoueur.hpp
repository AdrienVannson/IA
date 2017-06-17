#ifndef WAPERCUJOUEUR_HPP
#define WAPERCUJOUEUR_HPP

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include <memory>

#include "partie/Joueur/Player.hpp"


class WApercuJoueur : public QWidget
{
    Q_OBJECT

public:

    explicit WApercuJoueur (QWidget *parent=0);

    void setObject (const std::shared_ptr<const Player> &joueur);


private:

    std::shared_ptr<const Player> m_joueur;

    QPushButton *m_bouton;


};

#endif // WAPERCUJOUEUR_HPP
