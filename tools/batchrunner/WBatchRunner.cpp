#include "WBatchRunner.hpp"

WBatchRunner::WBatchRunner(QWidget *parent) :
    QWidget(parent),
    m_nbJoueurs (4)
{
    m_layout = new QVBoxLayout;
    setLayout(m_layout);


    // Layout des joueurs
    QWidget *widgetJoueurs = new QWidget;
    m_layout->addWidget(widgetJoueurs);

    m_layoutJoueurs = new QVBoxLayout;
    widgetJoueurs->setLayout(m_layoutJoueurs);


    // Interface
    m_bouttonDemarrer = new QPushButton ("Démarrer");
    m_layout->addWidget(m_bouttonDemarrer);

    m_barreProgression = new QProgressBar;
    m_barreProgression->setValue(42);
    m_layout->addWidget(m_barreProgression);

    updateJoueurs();
}


void WBatchRunner::updateJoueurs ()
{
    for (QLineEdit *champ : m_champsJoueurs) {
        delete champ;
    }
    m_champsJoueurs.clear();

    for (int iJoueur=0; iJoueur<m_nbJoueurs; iJoueur++) {
        QLineEdit *champ = new QLineEdit ("-1");
        champ->setValidator( new QIntValidator(this) );

        m_layoutJoueurs->addWidget(champ);

        m_champsJoueurs.push_back(champ);
    }
}
