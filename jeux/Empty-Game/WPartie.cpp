#include "WPartie.hpp"

#include <QVBoxLayout>


WPartie::WPartie (QWidget *parent) :
    WAbstractPartie (parent)
{
    m_vue = new QGraphicsView;

    m_scene = new QGraphicsScene;
    m_vue->setScene(m_scene);

    // Layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_vue);
    setLayout(layout);
}

void WPartie::initialiserPartie ()
{
    m_scene->clear();

    // Couleur de fond
    m_scene->setBackgroundBrush(QBrush(QColor(200, 200, 200)));

    // Affichage du tour actuel
    m_affichageTourActuel = new QGraphicsSimpleTextItem;
    m_affichageTourActuel->setPos( QPoint(0, 0) );

    m_affichageTourActuel->setFont( QFont("Times", 30, QFont::Bold) );

    m_scene->addItem(m_affichageTourActuel);
}

void WPartie::afficherTourActuel ()
{
    m_affichageTourActuel->setText( QString::number(m_tourActuel) );
}
