#include "JoueurRegression.h"

JoueurRegression::JoueurRegression ()
{
    for (int iCoefficient=0; iCoefficient<NB_COEFFICIENTS; iCoefficient++) {
        m_coefficients[iCoefficient] = ((double)(rand() % 2000) / 10.0) - 100;
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

}