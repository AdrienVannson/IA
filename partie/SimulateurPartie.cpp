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
        const InformationsTourJoueur &informations = InformationsTourJoueurFactory::creerInformationsTourJoueur(*partie, idJoueur);

        Tour *tour = partie->dernierTour();

        Action action = joueurs[idJoueur]->jouerAction(informations);
        action.setIdJoueur(idJoueur);
        tour->setAction(action);

        Tour nouveauTour;
        nouveauTour.setSituationJeu(Simulateur::simulerAction(tour->situationJeu(), action));

        partie->addTour(nouveauTour);

        idJoueur = (idJoueur+1) % joueurs.size();
    }

    return partie;
}
