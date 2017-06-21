#include "InformationsTourJoueurFactory.h"

InformationsTourJoueurFactory::InformationsTourJoueurFactory ()
{

}

InformationsTourJoueur InformationsTourJoueurFactory::creerInformationsTourJoueur
    (const Partie &partie, const int idJoueur)
{
    const GameSituation &premiereSituation = (*partie.tours())[0].situationJeu();
    const GameSituation &derniereSituation = (*partie.tours())[partie.tours()->size()-1].situationJeu();


    InformationsTourJoueur informations;

    informations.m_idJoueur = idJoueur;

    for (int idJoueur=0; idJoueur<premiereSituation.nbJoueurs(); idJoueur++) {
        std::pair< std::pair<int, int>, std::pair<int, int> > donnees;

        donnees.first = GameSituation::coordonneesCellule(premiereSituation.positionJoueur(idJoueur));
        donnees.second = GameSituation::coordonneesCellule(derniereSituation.positionJoueur(idJoueur));

        informations.m_joueurs.push_back(donnees);
    }

    return informations;
}
