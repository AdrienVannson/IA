#include "initialiser.hpp"
#include "joueurs/JoueurSimple.hpp"
#include "joueurs/JoueurExterne.hpp"

void initialiser (MainWindow *fenetre)
{
    // Création des joueurs
    fenetre->joueursManager()->add( shared_ptr<pair<function<Joueur*()>, QString>> (
        new pair<function<Joueur*()>, QString> (
                function<Joueur *()> ( [](){ return new JoueurSimple(); } ),
                QString("Joueur simple")
        )
    ));

    fenetre->joueursManager()->add( shared_ptr<pair<function<Joueur*()>, QString>> (
        new pair<function<Joueur*()>, QString> (
                function<Joueur *()> ( [](){ return new JoueurExterne("./prog"); } ),
                QString("Joueur externe")
        )
    ));

    // Simulation d'une partie classique
    vector<shared_ptr<Joueur>> joueurs;
    joueurs.push_back(shared_ptr<Joueur>(fenetre->joueursManager()->get(0)->first()));
    joueurs.push_back(shared_ptr<Joueur>(fenetre->joueursManager()->get(0)->first()));
    fenetre->gameRunner()->runGame(joueurs);
}
