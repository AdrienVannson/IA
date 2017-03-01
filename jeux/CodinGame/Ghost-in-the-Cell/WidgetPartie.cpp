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
    m_modeleUsines = new QStandardItemModel;

    QStringList intitulesColonnes;
    intitulesColonnes.append(QString("ID"));
    intitulesColonnes.append(QString("Production"));
    intitulesColonnes.append(QString("Nb d'unités"));
    intitulesColonnes.append(QString("Nb tours bloqué"));

    m_modeleUsines->setHorizontalHeaderLabels(intitulesColonnes);

    QTableView *vueUsines = new QTableView;
    vueUsines->setModel(m_modeleUsines);
    m_layout->addWidget(vueUsines);


    // Troupes
    m_modeleTroupes = new QStandardItemModel();

    intitulesColonnes.clear();
    intitulesColonnes.append(QString("Nb d'unités"));
    intitulesColonnes.append(QString("Cible"));
    intitulesColonnes.append(QString("Nb tours restants"));
    intitulesColonnes.append(QString("Type"));

    m_modeleTroupes->setHorizontalHeaderLabels(intitulesColonnes);

    QTableView *vueTroupes = new QTableView;
    vueTroupes->setModel(m_modeleTroupes);
    m_layout->addWidget(vueTroupes);




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
    const SituationJeu &situationActuelle = (*m_partie->tours())[m_iTourActuel].situationJeu();

    // Tour actuel
    m_affichageITour->setText(QString::number(m_iTourActuel));

    // Usines
    for (unsigned int idUsine=0; idUsine<situationActuelle.usines()->size(); idUsine++) {
        const SituationJeu::Usine &usine = (*situationActuelle.usines())[idUsine];

        // Couleur
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

    // Troupes
    for (unsigned int iTroupe=0; iTroupe<situationActuelle.troupes()->size(); iTroupe++) {
        const SituationJeu::Troupe &troupe = (*situationActuelle.troupes())[iTroupe];

        // Couleur
        QBrush brosse;

        switch (troupe.m_idJoueur) {

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

        // Nombre d'unités
        QStandardItem *itemNbUnites = new QStandardItem(QString::number(troupe.m_nbUnites));
        itemNbUnites->setBackground(brosse);
        m_modeleTroupes->setItem(iTroupe, 0, itemNbUnites);

        // Cible
        QStandardItem *itemCible = new QStandardItem(QString::number(troupe.m_cible));
        itemCible->setBackground(brosse);
        m_modeleTroupes->setItem(iTroupe, 1, itemCible);

        // Nombre de tours restants
        QStandardItem *itemNbToursRestants = new QStandardItem(QString::number(troupe.m_nbToursRestants));
        itemNbToursRestants->setBackground(brosse);
        m_modeleTroupes->setItem(iTroupe, 2, itemNbToursRestants);

        // Type
        QStandardItem *itemType = new QStandardItem(troupe.m_estBombe ? "Bombe" : "Troupe");
        itemType->setBackground(brosse);
        m_modeleTroupes->setItem(iTroupe, 3, itemType);
    }
}
