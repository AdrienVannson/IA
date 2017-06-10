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

    if (m_manager->getObjets()->empty()) {
        return;
    }

    const int nbChiffresMaxId = QString::number((*m_manager->getObjets())[ m_manager->getObjets()->size()-1 ].first).size();

    for (std::pair<int, T*> infos : *m_manager->getObjets()) {
        QWidget *ligne = new QWidget;

        QHBoxLayout *layoutLigne = new QHBoxLayout;
        ligne->setLayout(layoutLigne);

        QToolButton *wId = new QToolButton;
        wId->setText( QString::number(infos.first).rightJustified(nbChiffresMaxId, '0') );
        layoutLigne->addWidget(wId);

        WT *widget = new WT;
        widget->setObjet(infos.second);

        layoutLigne->addWidget(widget);

        m_layoutLignes->addWidget(ligne);
    }
}
