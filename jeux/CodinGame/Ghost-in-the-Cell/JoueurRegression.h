#ifndef JOUEURREGRESSION_H
#define JOUEURREGRESSION_H

#include <array>

#include "partie/Joueur.h"
#include "partie/JoueurManager.h"


class JoueurRegression : public Joueur
{

public:

    JoueurRegression ();

    Action jouerAction (const InformationsTourJoueur &informations);

    void entrainer (JoueurManager *joueurManager);


private:

    static const int NB_COEFFICIENTS = 2;

    std::array<int, NB_COEFFICIENTS> m_coefficients;


};

#endif // JOUEURREGRESSION_H
