/*
 * Gère les parties
 *
 * Les parties ajoutées ne peuvent plus être modifiées par la suite
 */

#ifndef PARTIESMANAGER_H
#define PARTIESMANAGER_H

#include <QWidget>

#include <vector>

#include "Partie.h"


class PartiesManager : public QWidget
{
    Q_OBJECT


public:
    PartiesManager ();

    const std::vector<Partie*>* parties () const;
    Partie* getPartie (const int idPartie);
    void addPartie (Partie *nouvellePartie);



signals:

    void updated ();



private:
    std::vector<Partie*> m_parties;

};

#endif // PARTIESMANAGER_H
