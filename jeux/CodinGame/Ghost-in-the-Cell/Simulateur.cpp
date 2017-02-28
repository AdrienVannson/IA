#include "Simulateur.h"

Simulateur::Simulateur ()
{

}


SituationJeu Simulateur::simulerAction (const SituationJeu &situationDepart, const Action actionAJouer)
{
    m_situation = situationDepart;
    m_situation.addAction(actionAJouer);

    if (m_situation.actions()->size() == 2) { // Si tous les joueurs ont joué, simulation du tour

        avancerTroupes();

        for (const Action &action : *m_situation.actions()) {
            executerAction(action);
        }

        produireUnites();
        combattre();
        exploserBombes();
        verifierFin();

    }

    return m_situation;
}


/*
 * Fonctions de jeu
 */

void Simulateur::avancerTroupes ()
{
    for (SituationJeu::Troupe &troupe : *m_situation.troupes()) {
        troupe.m_nbToursRestants--;
    }
}

void Simulateur::executerAction (const Action &action)
{
    if (action.type() == Action::DEPLACEMENT) {

        const int source = action.information(0);

        SituationJeu::Usine &usineSource = (*m_situation.usines())[source];

        if (usineSource.m_proprietaire != action.idJoueur()) { // Impossible de déplacer les troupes adverses
            return;
        }

        const int cible = action.information(1);
        int nbEnvois = action.information(2);

        if (usineSource.m_nbUnites < nbEnvois) {
            nbEnvois = usineSource.m_nbUnites;
        }

        usineSource.m_nbUnites -= nbEnvois;

        SituationJeu::Troupe nouvelleTroupe;
        nouvelleTroupe.m_cible = cible;
        nouvelleTroupe.m_nbUnites = nbEnvois;
        nouvelleTroupe.m_nbToursRestants = m_situation.distance(source, cible);

        m_situation.addTroupe(nouvelleTroupe);

    }
    else if (action.type() == Action::BOMBE) {

        if (m_situation.nbBombesRestantes(action.idJoueur()) <= 0) { // Impossible de lancer plus de deux bombes
            return;
        }

        const int source = action.information(0);

        if ((*m_situation.usines())[source].m_proprietaire != action.idJoueur()) { // Impossible de lancer une bombe depuis une usine ennemie
            return;
        }

        const int cible = action.information(1);

        SituationJeu::Troupe nouvelleBombe;
        nouvelleBombe.m_cible = cible;
        nouvelleBombe.m_estBombe = true;
        nouvelleBombe.m_nbToursRestants = m_situation.distance(source, cible);

        m_situation.addTroupe(nouvelleBombe);
        m_situation.utiliserBombe(action.idJoueur());

    }
    else if (action.type() == Action::AMELIORATION) {

    }
}

void Simulateur::produireUnites ()
{
    for (SituationJeu::Usine &usine : *m_situation.usines()) {

        if (usine.m_nbToursBloquesRestants > 0) {
            usine.m_nbToursBloquesRestants--;
        }
        else if (usine.m_proprietaire != SituationJeu::NEUTRE) {
            usine.m_nbUnites += usine.m_production;
        }

    }
}

void Simulateur::combattre ()
{

}

void Simulateur::exploserBombes ()
{

}

bool Simulateur::verifierFin ()
{

}
