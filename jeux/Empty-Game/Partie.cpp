#include "Partie.hpp"

Partie::Partie ()
{}

const std::vector<SituationJeu>& Partie::situationsJeu () const
{
    return m_situationsJeu;
}
void Partie::ajouterSituationJeu (const SituationJeu &sit)
{
    m_situationsJeu.push_back(sit);
}

const std::vector<Action>& Partie::actions () const
{
    return m_actions;
}
void Partie::ajouterAction (const Action &action)
{
    m_actions.push_back(action);
}
