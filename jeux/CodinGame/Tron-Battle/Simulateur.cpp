#include "Simulateur.h"

SituationJeu Simulateur::m_situationJeu;



Simulateur::Simulateur ()
{

}


SituationJeu Simulateur::simulerAction (const SituationJeu &situationDepart, const Action &actionAJouer)
{
    m_situationJeu = situationDepart;
    m_situationJeu.addAction(actionAJouer);

    if ((int)m_situationJeu.actionJouees()->size() == m_situationJeu.nbJoueurs()) {

        for (const Action &action : *m_situationJeu.actionJouees()) {
            jouerAction(action);
        }

        m_situationJeu.actionJouees()->clear();
    }

    return m_situationJeu;
}


void Simulateur::jouerAction (const Action &action)
{

}
