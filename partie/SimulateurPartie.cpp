#include "SimulateurPartie.h"

SimulateurPartie::SimulateurPartie ()
{

}

Partie* SimulateurPartie::simulerPartie (const SituationJeu &sitDepart, std::vector< std::shared_ptr<Joueur> > &joueurs)
{
    Partie *partie = new Partie;
    partie->addTour(Tour(sitDepart));

    while (!partie->dernierTour()->situationJeu().estFini()) {

        Tour *tour = partie->dernierTour();
        const int iJoueur = tour->situationJeu().iPlayer();

        const InformationsTourJoueur &informations = InformationsTourJoueurFactory::creerInformationsTourJoueur(*partie, iJoueur);

        Action action = joueurs[iJoueur]->jouerAction(informations);
        tour->setAction(action);

        Tour nouveauTour;
        nouveauTour.setSituationJeu(Arbitre::simulerAction(tour->situationJeu(), action));

        partie->addTour(nouveauTour);
    }

    return partie;
}
