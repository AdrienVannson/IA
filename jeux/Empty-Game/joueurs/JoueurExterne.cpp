#include "JoueurExterne.hpp"

using namespace std;


JoueurExterne::JoueurExterne (const std::string &chemin) :
    JoueurExterneAbstrait (chemin)
{}

JoueurExterne::~JoueurExterne ()
{}


void JoueurExterne::debutPartie (const Partie &partie, const int idJoueur)
{
    UNUSED(idJoueur);

    executerProgramme();

    string aEnvoyer;
    aEnvoyer.append("42\n");
    send(aEnvoyer);
}

Action JoueurExterne::jouerAction (const Partie &partie, const int idJoueur)
{
    string aEnvoyer;
    aEnvoyer.append("42\n");
    send(aEnvoyer);


    const string sortie = getLine();

    return Action ();
}
