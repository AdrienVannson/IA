#include "JoueurManager.h"

JoueurManager::JoueurManager ()
{
}

JoueurManager::~JoueurManager ()
{
    for (std::pair<Joueur*, double> paire : m_joueurs) {
        delete paire.first;
    }
}

void JoueurManager::addJoueur (Joueur *nouveauJoueur)
{
    m_joueurs.push_back( std::make_pair(nouveauJoueur, -1) );
}

double JoueurManager::getRatioVictoire (Joueur* joueur, const int nbParties) const
{
    if (m_joueurs.size() == 0) {
        return 0.5;
    }

    int nbVictoires = 0;

    for (int iPartie=0; iPartie<nbParties; iPartie++) {
        SituationJeu situationDepart;
        situationDepart.initialiser();

        std::vector<Joueur*> joueurs;
        joueurs.push_back(m_joueurs[iPartie % m_joueurs.size()].first);
        joueurs.push_back(joueur);

        Partie *partie = SimulateurPartie::simulerPartie(situationDepart, joueurs);

        if (partie->dernierTour()->situationJeu().idVainqueur() == 1) {
            nbVictoires++;
        }

        delete partie;
    }

    return (double)nbVictoires / (double)nbParties;
}
