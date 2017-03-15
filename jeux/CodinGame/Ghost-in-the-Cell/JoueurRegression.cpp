#include "JoueurRegression.h"

JoueurRegression::JoueurRegression ()
{
    for (int iCoefficient=0; iCoefficient<NB_COEFFICIENTS; iCoefficient++) {
        m_coefficients[iCoefficient] = (rand() % 20) - 10;
    }
}


Action JoueurRegression::jouerAction (const InformationsTourJoueur &informations)
{
    Action actionMax;
    double scoreMax = - 1000 * 1000 * 1000;

    const std::vector<SituationJeu::Usine> *usines = informations.situationJeu()->usines();

    for (unsigned int idSource=0; idSource<usines->size(); idSource++) {
        const SituationJeu::Usine &source = (*usines)[idSource];

        if (source.m_proprietaire != 1) {
            continue;
        }

        for (unsigned int idCible=0; idCible<usines->size(); idCible++) {
            const SituationJeu::Usine &cible = (*usines)[idCible];

            double score = 0;

            score += m_coefficients[0];
            score += m_coefficients[1] * informations.situationJeu()->distance(idSource, idCible);
            score += m_coefficients[2] * (cible.m_proprietaire == -1);
            score += m_coefficients[3] * (cible.m_proprietaire == 0);
            score += m_coefficients[4] * (cible.m_proprietaire == 1);
            score += m_coefficients[5] * cible.m_nbUnites;
            score += m_coefficients[6] * cible.m_production;
            score += m_coefficients[7] * cible.m_nbUnites * (cible.m_proprietaire == 1);
            score += m_coefficients[8] * cible.m_production * (cible.m_proprietaire == 1);
            score += m_coefficients[9] * source.m_nbUnites;
            score += m_coefficients[10] * source.m_production;


            if (score > scoreMax) {
                scoreMax = score;

                Action action;
                action.setType(Action::DEPLACEMENT);
                action.setInformation(idSource, 0);
                action.setInformation(idCible, 1);
                action.setInformation(1, 2);

                actionMax = action;
            }
        }
    }

    return actionMax;
}


void JoueurRegression::entrainer (JoueurManager *joueurManager)
{
    for (int i=0; i<300; i++) { // Nombre d'itérations de l'entrainement
        qDebug() << "Iteration:" << i;

        for (int iCoefficient=0; iCoefficient<NB_COEFFICIENTS; iCoefficient++) {
            double meilleurDelta = 0;
            double meilleurScore = - 1000 * 1000 * 1000;

            for (int delta=-1; delta<=1; delta++) {

                m_coefficients[iCoefficient] += delta;

                int nbMatchs = 20+i/10;
                if (i > 280) {
                    nbMatchs = 100;
                }

                const double score = joueurManager->getRatioVictoire(this, nbMatchs);
                m_coefficients[iCoefficient] -= delta;

                if (score > meilleurScore) {
                    meilleurScore = score;
                    meilleurDelta = delta;
                }
            }

            m_coefficients[iCoefficient] += meilleurDelta;
        }

    }
}


const std::array<double, JoueurRegression::NB_COEFFICIENTS>* JoueurRegression::coefficients () const
{
    return &m_coefficients;
}
