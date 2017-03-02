#ifndef JOUEURMANAGER_H
#define JOUEURMANAGER_H

#include <utility>
#include <vector>

#include "Joueur.h"
#include "SimulateurPartie.h"


class JoueurManager
{

public:
    JoueurManager ();
    ~JoueurManager ();

    void addJoueur (Joueur* nouveauJoueur);

    double getRatioVictoire (Joueur* joueur, const int nbParties) const;


private:
    std::vector< std::pair<Joueur*, double> > m_joueurs; // Joueur ; score

};

#endif // JOUEURMANAGER_H
