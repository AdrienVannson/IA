#include "simulerPartie.hpp"

using namespace std;

shared_ptr<Partie> simulerPartie (vector<shared_ptr<Joueur>> &joueurs)
{
    // Initialisation de la première situation
    SituationJeu sitDepart;

    // Initialisation de la partie
    shared_ptr<Partie> partie (new Partie);
    partie->m_situationsJeu.push_back(sitDepart);

    // Initialisation des joueurs
    for (unsigned int iJoueur=0; iJoueur<joueurs.size(); iJoueur++) {
        joueurs[iJoueur]->debutPartie(*partie, iJoueur);
    }

    int iJoueur = 0;

    while (!partie->m_situationsJeu.back().estFini()) {
        const SituationJeu &sit = partie->m_situationsJeu.back();

        const Action action = joueurs[iJoueur]->jouerAction(*partie, iJoueur);
        partie->m_actions.push_back(action);

        SituationJeu nouvelleSit = sit;
        nouvelleSit.simulerAction(action);

        partie->m_situationsJeu.push_back(nouvelleSit);

        iJoueur = (iJoueur + 1) % joueurs.size();
    }

    return partie;
}
