#ifndef JOUEURSIMPLE_HPP
#define JOUEURSIMPLE_HPP

#include "Joueur.hpp"


class JoueurSimple : public Joueur
{
public:
    JoueurSimple ();
    ~JoueurSimple ();

    Action jouerAction (const Partie &partie, const int idJoueur);
};


#endif // JOUEURSIMPLE_HPP
