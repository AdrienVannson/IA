#include "WidgetPartie.h"

WidgetPartie::WidgetPartie(QWidget *parent) :
    QWidget (parent),
    m_iTourActuel (0)
{
    // Layout principal
    m_layout = new QVBoxLayout;
    setLayout(m_layout);

    // Affichage du tour
    m_affichageITour = new QLabel;
    m_layout->addWidget(m_affichageITour);

    // Usines
    m_modeleUsines = new QStandardItemModel(5, 3);

    QStringList intitulesColonnes;
    intitulesColonnes.append(QString("ID"));
    intitulesColonnes.append(QString("Production"));
    intitulesColonnes.append(QString("Nb d'unités"));
    intitulesColonnes.append(QString("Nb tours bloqué"));

    m_modeleUsines->setHorizontalHeaderLabels(intitulesColonnes);


    QTableView *vue = new QTableView;
    vue->setModel(m_modeleUsines);

    m_layout->addWidget(vue);


    // Timer
    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(tourSuivant()));
}

QSize WidgetPartie::minimumSizeHint() const
{
    return QSize (512, 512);
}


void WidgetPartie::afficherPartie (const Partie *partie)
{
    m_partie = partie;
    m_iTourActuel = 0;
    afficherTourActuel();

    m_timer->start();
}

void WidgetPartie::tourSuivant ()
{
    m_iTourActuel = (m_iTourActuel+1) % m_partie->tours()->size();
    afficherTourActuel();
}


void WidgetPartie::afficherTourActuel ()
{
    m_affichageITour->setText(QString::number(m_iTourActuel));

    const SituationJeu &situationActuelle = (*m_partie->tours())[m_iTourActuel].situationJeu();

    for (unsigned int idUsine=0; idUsine<situationActuelle.usines()->size(); idUsine++) {
        const SituationJeu::Usine &usine = (*situationActuelle.usines())[idUsine];

        QBrush brosse;

        switch (usine.m_proprietaire) {

        case SituationJeu::NEUTRE:
            brosse = QBrush(QColor(0, 0, 0, 30));
            break;

        case 0:
            brosse = QBrush(QColor(0, 0, 255, 90));
            break;

        case 1:
            brosse = QBrush(QColor(0, 255, 0, 90));
            break;

        }

        // Id
        QStandardItem *itemId = new QStandardItem(QString::number(idUsine));
        itemId->setBackground(brosse);
        m_modeleUsines->setItem(idUsine, 0, itemId);

        // Production
        QStandardItem *itemProduction = new QStandardItem(QString::number(usine.m_production));
        itemProduction->setBackground(brosse);
        m_modeleUsines->setItem(idUsine, 1, itemProduction);

        // Nombre d'unités
        QStandardItem *itemNbUnites= new QStandardItem(QString::number(usine.m_nbUnites));
        itemNbUnites->setBackground(brosse);
        m_modeleUsines->setItem(idUsine, 2, itemNbUnites);

        // Nombre de tours bloqués restants
        QStandardItem *itemNbToursBloquesRestants = new QStandardItem(QString::number(usine.m_nbToursBloquesRestants));
        itemNbToursBloquesRestants->setBackground(brosse);
        m_modeleUsines->setItem(idUsine, 3, itemNbToursBloquesRestants);
    }
}
