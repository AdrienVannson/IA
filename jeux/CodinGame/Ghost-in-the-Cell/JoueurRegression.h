#ifndef JOUEURREGRESSION_H
#define JOUEURREGRESSION_H

#include "partie/Joueur.h"
#include "partie/JoueurManager.h"


class JoueurRegression : public Joueur
{

public:

    JoueurRegression (JoueurManager *joueurManager);

    Action jouerAction (const InformationsTourJoueur &informations);

    void entrainer ();


private:

    JoueurManager *m_joueurManager;

};

#endif // JOUEURREGRESSION_H
