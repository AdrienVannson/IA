#ifndef WAPERCUJOUEUR_HPP
#define WAPERCUJOUEUR_HPP

#include <memory>
#include <functional>

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include "Joueur.hpp"


class WApercuJoueur : public QWidget
{
    Q_OBJECT

public:
    explicit WApercuJoueur (QWidget *parent=0);

    void setObject (const std::shared_ptr<const std::pair< std::function<Joueur*()>, QString> > &joueur);


private:
    std::shared_ptr<const std::pair< std::function<Joueur*()>, QString>> m_joueur;

    QPushButton *m_bouton;

};

#endif // WAPERCUJOUEUR_HPP
