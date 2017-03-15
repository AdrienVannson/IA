#ifndef JOUEURSMANAGER_H
#define JOUEURSMANAGER_H

#include <utility>
#include <vector>

#include "Joueur.h"
#include "SimulateurPartie.h"


class JoueursManager
{

public:
    JoueursManager ();
    ~JoueursManager ();

    void addJoueur (Joueur* nouveauJoueur);

    double getRatioVictoire (Joueur* joueur, const int nbParties) const;


private:
    std::vector< std::pair<Joueur*, double> > m_joueurs; // Joueur ; score

};

#endif // JOUEURSMANAGER_H
