#include "Simulateur.h"

/*
 * Membres statiques
 */

SituationJeu Simulateur::m_situation;



Simulateur::Simulateur ()
{

}


SituationJeu Simulateur::simulerAction (const SituationJeu &situationDepart, const Action &actionAJouer)
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

        m_situation.supprimerLesActions();
    }

    m_situation.incrementerNbToursEcoules();

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
    if (action.type() == Action::ATTENTE) {
        return;
    }


    const int source = action.information(0);
    SituationJeu::Usine &usineSource = (*m_situation.usines())[source];

    if (usineSource.m_proprietaire != action.idJoueur()) { // Impossible d'effectuer une action sur une usine adverse
        return;
    }

    if (action.type() == Action::DEPLACEMENT) {

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
        nouvelleTroupe.m_idJoueur = action.idJoueur();

        m_situation.addTroupe(nouvelleTroupe);

    }
    else if (action.type() == Action::BOMBE) {

        if (m_situation.nbBombesRestantes(action.idJoueur()) <= 0) { // Impossible de lancer plus de deux bombes
            return;
        }

        const int cible = action.information(1);

        SituationJeu::Troupe nouvelleBombe;
        nouvelleBombe.m_cible = cible;
        nouvelleBombe.m_estBombe = true;
        nouvelleBombe.m_nbToursRestants = m_situation.distance(source, cible);
        nouvelleBombe.m_idJoueur = action.idJoueur();

        m_situation.addTroupe(nouvelleBombe);
        m_situation.utiliserBombe(action.idJoueur());

    }
    else if (action.type() == Action::AMELIORATION) {

        if (usineSource.m_nbUnites >= 10 && usineSource.m_production < 3) {
            usineSource.m_nbUnites -= 10;
            usineSource.m_production++;
        }

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
    std::stack<int> iTroupesASupprimer;

    for (unsigned int iTroupe=0; iTroupe<m_situation.troupes()->size(); iTroupe++) {
        const SituationJeu::Troupe &troupe = (*m_situation.troupes())[iTroupe];

        if (!troupe.m_estBombe && troupe.m_nbToursRestants == 0) {
            SituationJeu::Usine &usine = (*m_situation.usines())[troupe.m_cible];

            int signe = 1;
            if (troupe.m_idJoueur != usine.m_proprietaire) {
                signe = -1;
            }

            usine.m_nbUnites += signe * troupe.m_nbUnites;

            if (usine.m_nbUnites < 0) {
                usine.m_nbUnites = -usine.m_nbUnites;
                usine.m_proprietaire = troupe.m_idJoueur;
            }

            iTroupesASupprimer.push(iTroupe);
        }
    }

    while (iTroupesASupprimer.size()) { // Suppression des troupes à supprimer
        const int iASupprimer = iTroupesASupprimer.top();
        m_situation.troupes()->erase(m_situation.troupes()->begin() + iASupprimer);
        iTroupesASupprimer.pop();
    }
}

void Simulateur::exploserBombes ()
{
    std::stack<int> iBombesASupprimer;

    for (unsigned int iTroupe=0; iTroupe<m_situation.troupes()->size(); iTroupe++) {
        const SituationJeu::Troupe &troupe = (*m_situation.troupes())[iTroupe];

        if (troupe.m_estBombe && troupe.m_nbToursRestants == 0) {

            SituationJeu::Usine &usine = (*m_situation.usines())[troupe.m_cible];

            int degats = std::max(usine.m_nbUnites/2, 10);

            usine.m_nbUnites -= degats;

            if (usine.m_nbUnites < 0) {
                usine.m_nbUnites = 0;
            }

            usine.m_nbToursBloquesRestants = 5;

            iBombesASupprimer.push(iTroupe);
        }

    }

    while (iBombesASupprimer.size()) { // Suppression des bombes à supprimer
        const int iASupprimer = iBombesASupprimer.top();
        m_situation.troupes()->erase(m_situation.troupes()->begin() + iASupprimer);
        iBombesASupprimer.pop();
    }
}

void Simulateur::verifierFin ()
{
    std::array<int, 2> nbUnitesParJoueur = {0, 0};
    std::array<bool, 2> peutProduire = {false, false};

    for (const SituationJeu::Usine &usine : *m_situation.usines()) {
        nbUnitesParJoueur[usine.m_proprietaire] += usine.m_nbUnites;

        if (usine.m_production > 0) {
            peutProduire[usine.m_production] = true;
        }
    }

    if (m_situation.nbToursEcoules() >= 400) {

        if (nbUnitesParJoueur[0] > nbUnitesParJoueur[1]) {
            m_situation.setIdVainqueur(0);
        }
        else if (nbUnitesParJoueur[0] < nbUnitesParJoueur[1]) {
            m_situation.setIdVainqueur(1);
        }
        else {
            m_situation.setIdVainqueur(-2);
        }

    }
    else {

        for (int idJoueur=0; idJoueur<2; idJoueur++) {
            if (nbUnitesParJoueur[idJoueur] == 0 && !peutProduire[idJoueur]) {
                m_situation.setIdVainqueur(!idJoueur);
            }
        }

    }
}
