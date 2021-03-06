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

WApercuPartie::~WApercuPartie ()
{
}


void WApercuPartie::setObject (const shared_ptr<const Partie> &partie)
{
    m_partie = partie;
}


void WApercuPartie::emettreAfficher ()
{
    emit show (m_partie);
}
