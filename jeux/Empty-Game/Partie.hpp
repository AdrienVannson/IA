#ifndef PARTIE_HPP
#define PARTIE_HPP

#include <vector>

#include "SituationJeu.hpp"


class Partie
{
public:
    Partie ();

    const std::vector<SituationJeu>& situationsJeu () const;
    void ajouterSituationJeu (const SituationJeu &sit);

    const std::vector<Action>& actions () const;
    void ajouterAction (const Action &action);


private:
    std::vector<SituationJeu> m_situationsJeu;
    std::vector<Action> m_actions;

};

#endif // PARTIE_HPP
