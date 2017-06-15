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

    m_layoutLignes = new QVBoxLayout;
    widget->setLayout(m_layoutLignes);
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
    while ((enfant = m_layoutLignes->takeAt(0))) {
        delete enfant->widget();
        delete enfant;
    }

    if (m_manager->getAll()->empty()) {
        return;
    }


    int iObjet = 0;

    for (const std::shared_ptr<const T> &objet : *m_manager->getAll()) {
        QWidget *ligne = new QWidget;

        QHBoxLayout *layoutLigne = new QHBoxLayout;
        ligne->setLayout(layoutLigne);

        WT *widget = new WT;
        widget->setObject(objet);

        layoutLigne->addWidget(widget);

        m_layoutLignes->addWidget(ligne);

        iObjet++;
    }
}
