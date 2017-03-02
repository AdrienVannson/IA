#include "JoueurNaif.h"

JoueurNaif::JoueurNaif ()
{

}

Action JoueurNaif::jouerAction (const InformationsTourJoueur &informations)
{
    const std::vector<SituationJeu::Usine> *usines = informations.situationJeu()->usines();

    int source = 0;
    int cible = -1;

    for (unsigned int idUsine=0; idUsine<usines->size(); idUsine++) {
        const SituationJeu::Usine &usine = (*usines)[idUsine];

        if (usine.m_proprietaire == 1) {
            source = idUsine;
        }
        else if (usine.m_proprietaire == 0 || (usine.m_proprietaire == -1 && cible == -1)) {
            cible = idUsine;
        }

    }

    if (cible == -1) {
        cible = 0;
    }

    Action action;

    action.setType(Action::DEPLACEMENT);
    action.setInformation(source, 0);
    action.setInformation(cible, 1);
    action.setInformation(1, 2);

    return action;
}
