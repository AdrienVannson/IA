#include "WManager.hpp"

template<class T, class WV>
WManager<T, WV>::WManager (QWidget *parent) :
    QWidget (parent),
    m_manager (0)
{
    m_layout = new QVBoxLayout;
    setLayout(m_layout);

    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    m_layout->addWidget(scrollArea);

    QWidget *widget = new QWidget;
    scrollArea->setWidget(widget);

    m_layoutObjets = new QVBoxLayout;
    widget->setLayout(m_layoutObjets);
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
    while ((enfant = m_layoutObjets->takeAt(0))) {
        delete enfant->widget();
        delete enfant;
    }

    for (std::pair<int, T*> infos : *m_manager->getObjets()) {
        WT *widget = new WT;
        widget->setObjet(infos.second);

        m_layoutObjets->addWidget(widget);
    }
}
