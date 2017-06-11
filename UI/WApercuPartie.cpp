#include "WApercuPartie.hpp"

WApercuPartie::WApercuPartie (QWidget *parent) :
    QWidget (parent)
{
    QHBoxLayout *layout = new QHBoxLayout (this);

    QToolButton *boutonAfficher = new QToolButton;
    boutonAfficher->setIcon(QIcon(":/icons/show.png"));

    layout->addWidget(boutonAfficher);


    layout->addWidget( new QPushButton("Partie") );
}


void WApercuPartie::setObjet (const Partie *partie)
{

}
