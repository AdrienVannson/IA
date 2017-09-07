#ifndef EVALUATIONABSTRAITE_HPP
#define EVALUATIONABSTRAITE_HPP

#include "Partie.hpp"


class EvaluationAbstraite
{

public:

    EvaluationAbstraite ();
    virtual ~EvaluationAbstraite ();


    virtual std::vector<int> getScores (const Partie &partie) = 0;


};

#endif // EVALUATIONABSTRAITE_HPP
