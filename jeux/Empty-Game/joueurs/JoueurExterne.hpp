#ifndef JOUEUREXTERNE_HPP
#define JOUEUREXTERNE_HPP

#include <string>

#include "joueurs/JoueurExterneAbstrait.hpp"


class JoueurExterne : public JoueurExterneAbstrait
{
public:
    JoueurExterne (const std::string &chemin="");
    ~JoueurExterne ();

    void debutPartie (const Partie &partie, const int idJoueur);
    Action jouerAction (const Partie &partie, const int idJoueur);
};

#endif // JOUEUREXTERNE_HPP
