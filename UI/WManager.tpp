#include "WManager.hpp"

template<class T, class WV>
WManager<T, WV>::WManager (QWidget *parent) :
    WManagerQWidget (parent),
    m_manager (0)
{
    m_layout = new QVBoxLayout;
    setLayout(m_layout);


    QWidget *parametrage = new QWidget;
    QHBoxLayout *layoutParametrage = new QHBoxLayout;
    parametrage->setLayout(layoutParametrage);
    m_layout->addWidget(parametrage);


    m_champPremierAffiche = new QLineEdit ();
    m_champPremierAffiche->setPlaceholderText("Premier affiché");
    m_champPremierAffiche->setValidator( new QIntValidator(this) );
    m_champPremierAffiche->setText("0");
    layoutParametrage->addWidget(m_champPremierAffiche);

    m_champNbAffiches = new QLineEdit ();
    m_champNbAffiches->setPlaceholderText("Nombre à afficher");
    m_champNbAffiches->setValidator( new QIntValidator(this) );
    m_champNbAffiches->setText("10");
    layoutParametrage->addWidget(m_champNbAffiches);

    QPushButton *valider = new QPushButton ("GO");
    layoutParametrage->addWidget(valider);
    connect (valider, &QPushButton::clicked, this, &WManager::actualiser);



    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setMinimumWidth(240);
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

    if (m_manager->getAll().empty()) {
        return;
    }


    const int iDebut = m_champPremierAffiche->text().toInt();
    const int iFin = iDebut + m_champNbAffiches->text().toInt();

    for (int iObjet=iDebut; iObjet<iFin && iObjet < (int)m_manager->size(); iObjet++) {

        const std::shared_ptr<const T> &objet = m_manager->get(iObjet);

        QWidget *ligne = new QWidget;

        QHBoxLayout *layoutLigne = new QHBoxLayout;
        ligne->setLayout(layoutLigne);

        WT *widget = new WT;
        widget->setObject(objet);
        emit widgetCreated(widget);

        layoutLigne->addWidget(widget);

        m_layoutLignes->addWidget(ligne);
    }
}
