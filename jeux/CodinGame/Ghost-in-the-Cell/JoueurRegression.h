#ifndef JOUEURREGRESSION_H
#define JOUEURREGRESSION_H

#include <QDebug>

#include <array>

#include "partie/Joueur.h"
#include "partie/JoueurManager.h"


class JoueurRegression : public Joueur
{

public:

    static const int NB_COEFFICIENTS = 5;



    JoueurRegression ();

    Action jouerAction (const InformationsTourJoueur &informations);

    void entrainer (JoueurManager *joueurManager);

    const std::array<double, NB_COEFFICIENTS>* coefficients () const;


private:

    std::array<double, NB_COEFFICIENTS> m_coefficients;


};

#endif // JOUEURREGRESSION_H
