#ifndef WPARTIE_HPP
#define WPARTIE_HPP

#include <QGraphicsSimpleTextItem>
#include <QGraphicsView>

#include "Partie.hpp"
#include "UI/WAbstractPartie.hpp"


class WPartie : public WAbstractPartie
{
    Q_OBJECT

public:
    explicit WPartie (QWidget *parent = 0);

protected:
    virtual void initialiserPartie () override;
    virtual void afficherTourActuel () override;

private:
    QGraphicsView *m_vue;
    QGraphicsScene *m_scene;

    // Élements de la scène
    QGraphicsSimpleTextItem *m_affichageTourActuel;
};

#endif // WPARTIE_HPP
