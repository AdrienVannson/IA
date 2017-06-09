#include "WManager.hpp"

template<class T, class WV>
WManager<T, WV>::WManager (QWidget *parent) :
    QWidget (parent),
    m_manager (0)
{
    m_layout = new QVBoxLayout;
    setLayout(m_layout);
}

template<class T, class WT>
void WManager<T, WT>::setManager (const Manager<T> *manager)
{
    m_manager = manager;
    actualiser();
}

template<class T, class WT>
void WManager<T, WT>::actualiser ()
{
    // Nettoyage du layout
    QLayoutItem *enfant;
    while ((enfant = m_layout->takeAt(0))) {
        delete enfant->widget();
        delete enfant;
    }

    for (std::pair<int, T*> infos : *m_manager->getObjets()) {
        QPushButton *bouton = new QPushButton (QString::number(infos.first));
        m_layout->addWidget(bouton);
    }
}
