#include "WApercuPartie.hpp"

WApercuPartie::WApercuPartie (QWidget *parent) :
    QWidget (parent)
{
    QVBoxLayout *layout = new QVBoxLayout (this);

    layout->addWidget( new QPushButton("Partie") );
}


void WApercuPartie::setObjet (const Partie *partie)
{

}
