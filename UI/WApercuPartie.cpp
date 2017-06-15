#include "WApercuPartie.hpp"

WApercuPartie::WApercuPartie (QWidget *parent) :
    QWidget (parent)
{
    QHBoxLayout *layout = new QHBoxLayout (this);

    QToolButton *boutonAfficher = new QToolButton;
    boutonAfficher->setIcon(QIcon(":/icons/show.png"));

    connect(boutonAfficher, &QToolButton::clicked, this, &WApercuPartie::emettreAfficher);

    layout->addWidget(boutonAfficher);


    layout->addWidget( new QPushButton("Partie") );
}


void WApercuPartie::setObject (const std::shared_ptr<const PartieDecrite> &partie)
{
    m_partie = partie;
}


void WApercuPartie::emettreAfficher ()
{
    emit afficher(m_partie);
}
