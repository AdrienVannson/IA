#ifndef WPARTIE_HPP
#define WPARTIE_HPP

#include <QGraphicsSimpleTextItem>
#include <QGraphicsView>
#include <QVBoxLayout>

#include "Partie.hpp"
#include "UI/WAbstractPartie.hpp"
#include "UI/AffichageSimulateur.hpp"


class WPartie : public WAbstractPartie
{
    Q_OBJECT

public:
    explicit WPartie (QWidget *parent = 0);


private:
    void afficherPartie (const std::shared_ptr<const Partie> &partie);

    AffichageSimulateur *m_vue;
};

#endif // WPARTIE_HPP
