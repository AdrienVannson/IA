#ifndef JOUEURREGRESSION_H
#define JOUEURREGRESSION_H

#include "partie/Joueur.h"
#include "partie/JoueurManager.h"


class JoueurRegression : public Joueur
{

public:

    JoueurRegression ();

    Action jouerAction (const InformationsTourJoueur &informations);

    void entrainer (JoueurManager *joueurManager);


private:


};

#endif // JOUEURREGRESSION_H
