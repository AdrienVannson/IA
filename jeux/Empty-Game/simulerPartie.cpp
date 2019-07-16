#include "simulerPartie.hpp"

using namespace std;

shared_ptr<Partie> simulerPartie (vector<shared_ptr<Joueur>> &joueurs)
{
    // Initialisation de la première situation
    SituationJeu sitDepart;

    // Initialisation de la partie
    shared_ptr<Partie> partie (new Partie);
    partie->ajouterSituationJeu(sitDepart);

    // Initialisation des joueurs
    for (unsigned int iJoueur=0; iJoueur<joueurs.size(); iJoueur++) {
        joueurs[iJoueur]->debutPartie(*partie, iJoueur);
    }

    int iJoueur = 0;

    while (!partie->situationsJeu().back().estFini()) {
        const SituationJeu &sit = partie->situationsJeu().back();

        const Action action = joueurs[iJoueur]->jouerAction(*partie, iJoueur);
        partie->ajouterAction(action);

        SituationJeu nouvelleSit = sit;
        nouvelleSit.simulerAction(action);

        partie->ajouterSituationJeu(nouvelleSit);

        iJoueur = (iJoueur + 1) % joueurs.size();
    }

    return partie;
}
