#include "WidgetPartie.h"


WidgetPartie::WidgetPartie(QWidget *parent) :
    WidgetPartieGeneral (parent)
{
    m_vue = new QGraphicsView;

    // Layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_vue);
    setLayout(layout);

    m_scene = new QGraphicsScene;
    m_vue->setScene(m_scene);
}

QSize WidgetPartie::minimumSizeHint() const
{
    return QSize(ZOOM*SituationJeu::NB_COLONNES + 100, ZOOM*SituationJeu::NB_LIGNES + 100);
}


void WidgetPartie::afficherGrilleVide ()
{
    m_scene->clear();

    m_scene->setBackgroundBrush(QBrush(QColor(39, 71, 60))); // Couleur de fond: vert


    // Affichage de la grille de jeu
    QRect rectanglePlateau(0, 0, ZOOM*SituationJeu::NB_COLONNES, ZOOM*SituationJeu::NB_LIGNES);

    m_scene->addRect(rectanglePlateau);

    for (int iColonne=1; iColonne<SituationJeu::NB_COLONNES; iColonne++) {
        m_scene->addLine(ZOOM*iColonne, 0, ZOOM*iColonne, ZOOM*SituationJeu::NB_LIGNES);
    }

    for (int iLigne=1; iLigne<SituationJeu::NB_LIGNES; iLigne++) {
        m_scene->addLine(0, ZOOM*iLigne, ZOOM*SituationJeu::NB_COLONNES, ZOOM*iLigne);
    }
}

void WidgetPartie::afficherTourActuel ()
{
    afficherGrilleVide();

    QFont police;
    police.setPointSize(21);

    QGraphicsSimpleTextItem *textItem = m_scene->addSimpleText(QString::number(m_iTourActuel), police);
    textItem->setPos(0, -2*ZOOM);


    // Affichage des cellules
    const SituationJeu &sitJeu = (*m_partie.tours())[m_iTourActuel].situationJeu();

    for (int iLigne=0; iLigne<SituationJeu::NB_LIGNES; iLigne++) {
        for (int iColonne=0; iColonne<SituationJeu::NB_COLONNES; iColonne++) {

            const int cellule = sitJeu.cellule(iLigne, iColonne);

            if (cellule == SituationJeu::VIDE) {
                continue;
            }

            QColor couleur;

            // Sélection de la couleur correspondant au joueur
            switch (cellule) {

            case 0:
                couleur = QColor(255, 0, 0);
                break;

            case 1:
                couleur = QColor(0, 255, 0);
                break;

            case 2:
                couleur = QColor(0, 0, 255);
                break;

            case 3:
                couleur = QColor(255, 255, 255);
                break;

            default:
                break;

            }

            m_scene->addRect(iColonne*ZOOM, iLigne*ZOOM, ZOOM, ZOOM, QPen(QColor()), QBrush(couleur));

        }
    }
}
