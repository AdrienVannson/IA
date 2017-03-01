#include "SimulateurPartie.h"

SimulateurPartie::SimulateurPartie ()
{

}

Partie* SimulateurPartie::simulerPartie (const SituationJeu &sitDepart, std::vector<Joueur*> &joueurs)
{
    Partie *partie = new Partie;
    partie->addTour(Tour(sitDepart));

    int idJoueur = 0;

    while (!partie->dernierTour()->situationJeu().estFini()) {
        Tour *tour = partie->dernierTour();

        const Action &action = joueurs[idJoueur++]->jouerAction(InformationsTourJoueur(tour->situationJeu(), idJoueur));
        tour->setAction(action);

        Tour nouveauTour;
        nouveauTour.setSituationJeu(Simulateur::simulerAction(tour->situationJeu(), action));

        partie->addTour(nouveauTour);
    }

    return partie;
}