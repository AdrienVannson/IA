#include "simulerPartie.hpp"

std::shared_ptr<Partie> simulerPartie (const SituationJeu &sitDepart, std::vector< std::shared_ptr<Joueur> > &joueurs)
{
    std::shared_ptr<Partie> partie (new Partie);
    partie->addTour(Tour(sitDepart));

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
        nouveauTour.setSituationJeu(Arbitre::simulerAction(tour.situationJeu(), action));

        partie->addTour(nouveauTour);
    }

    return partie;
}
