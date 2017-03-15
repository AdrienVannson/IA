#include "JoueursManager.h"

JoueursManager::JoueursManager ()
{
}

JoueursManager::~JoueursManager ()
{
    for (std::pair<Joueur*, double> paire : m_joueurs) {
        delete paire.first;
    }
}

void JoueursManager::addJoueur (Joueur *nouveauJoueur)
{
    m_joueurs.push_back( std::make_pair(nouveauJoueur, -1) );

    if (m_joueurs.size() >= 100) { // Suppression des joueurs trop nombreux
        delete m_joueurs[0].first;
        m_joueurs.erase(m_joueurs.begin());
    }
}

double JoueursManager::getRatioVictoire (Joueur* joueur, const int nbParties) const
{
    if (m_joueurs.size() == 0) {
        return 0.5;
    }

    int nbVictoires = 0;
    int nbEgalites = 0;

    for (int iPartie=0; iPartie<nbParties; iPartie++) {
        SituationJeu situationDepart;

        std::vector<Joueur*> joueurs;
        joueurs.push_back(m_joueurs[iPartie % m_joueurs.size()].first);
        joueurs.push_back(joueur);

        Partie *partie = SimulateurPartie::simulerPartie(situationDepart, joueurs);
        const int resultat = partie->dernierTour()->situationJeu().idVainqueur();

        if (resultat == 1) {
            nbVictoires++;
        }
        else if (resultat == -2) { // Égalité
            nbEgalites++;
        }

        delete partie;
    }

    return (double)(nbVictoires*2 + nbEgalites) / (double)(2*nbParties);
}
