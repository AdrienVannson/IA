/*
 * Fonctionne uniquement pour les jeux à deux joueurs
 */

#ifndef WBATCHRUNNER_HPP
#define WBATCHRUNNER_HPP

#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QIntValidator>
#include <QTableWidget>

#include <memory>
#include <vector>

#include "GameRunner.hpp"

using namespace std;


class CallbackBatchRunner : public QObject,
                            public CallbackFinSimulation
{
    Q_OBJECT

public:
    CallbackBatchRunner (const int iJoueur1, const int iJoueur2);

    virtual void operator() (const shared_ptr<Partie> &partie);

signals:
    void victoire (const int iJoueur, const int iAdversaire);

private:
    int m_iJoueur1, m_iJoueur2;

};


class WBatchRunner : public QWidget
{
    Q_OBJECT

public:
    explicit WBatchRunner ( GameRunner *gameRunner,
                            const vector<shared_ptr< std::pair< std::function<Joueur*()>, QString> >> &joueurs,
                            QWidget *parent=0
    );

public slots:
    void lancerParties ();
    void aGagne (const int iJoueur, const int iAdversaire);

private:

    // Interface
    QVBoxLayout *m_layout;
    QTableWidget *m_tableau;
    QLineEdit *m_champNbParties;
    QPushButton *m_bouttonDemarrer;

    GameRunner *m_gameRunner;
    vector<shared_ptr<std::pair< std::function<Joueur*()>, QString>>> m_joueurs;
    vector<vector<int>> m_nbVictoires;
};

#endif // WBATCHRUNNER_HPP
