#include "simulerPartie.hpp"

shared_ptr<Partie> simulerPartie (const SituationJeu &sitDepart, vector<shared_ptr<Joueur>> &joueurs)
{
    shared_ptr<Partie> partie (new Partie);
    partie->ajouterTour(Tour(sitDepart));

    // Initialisation des joueurs
    for (unsigned int iJoueur=0; iJoueur<joueurs.size(); iJoueur++) {
        joueurs[iJoueur]->debutPartie( InfosFactory::creerInfosDebutPartie(*partie, iJoueur) );
    }

    while (!partie->dernierTour().situationJeu().estFini()) {

        Tour &tour = partie->dernierTour();
        const int iJoueur = tour.situationJeu().iJoueur();

        const InfosTour &informations = InfosFactory::creerInfosTour(*partie, iJoueur);

        Action action = joueurs[iJoueur]->jouerAction(informations);
        tour.setAction(action);

        Tour nouveauTour;

        SituationJeu nouvelleSituation = tour.situationJeu();
        simulerAction(nouvelleSituation, action);

        nouveauTour.setSituationJeu(nouvelleSituation);

        partie->ajouterTour(nouveauTour);
    }

    return partie;
}
