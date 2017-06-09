#ifndef JOUEURSMANAGER_H
#define JOUEURSMANAGER_H

#include <utility>
#include <vector>

#include "Joueur/Joueur.h"
#include "SimulateurPartie.h"


class JoueursManager
{

public:
    JoueursManager ();
    ~JoueursManager ();

    void addJoueur (const Joueur* nouveauJoueur);

    int nbJoueurs () const;
    Joueur* getJoueur (const int idJoueur) const;


private:
    std::vector< std::pair<const Joueur*, double> > m_joueurs; // Joueur ; score

};

#endif // JOUEURSMANAGER_H
