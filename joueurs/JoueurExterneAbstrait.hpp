#ifndef JOUEUREXTERNEABSTRAIT_HPP
#define JOUEUREXTERNEABSTRAIT_HPP

#include <QApplication>
#include <QProcess>
#include <QEventLoop>
#include <QThread>

#include <string>

#include "partie/Joueur/Joueur.hpp"

using namespace std;


class Communication : public QObject
{
    Q_OBJECT

public:
    Communication (QObject *parent=0);

public slots:
    void demarrer (const string chemin);
    void envoyerDonnees (const string donnees);
    void lireDonnees ();
    void tuer ();

signals:
    void donneesRecues (const string donnees);

public:
    QProcess *m_processus;
};


class Intermediaire : public QObject
{
    Q_OBJECT

public:
    Intermediaire (QObject *parent=0);

    void demarrer (const string &chemin);
    void envoyerDonnees (const string donnees);
    void tuer ();

    string m_donnees;

public slots:
    void recevoirDonnees (const string donnees);

signals:
    void debut (const string chemin);
    void donneesEnvoyees (const string donnees);
    void doitTuer ();

};


class JoueurExterneAbstrait : public Joueur
{

public:
    JoueurExterneAbstrait (const string chemin);
    ~JoueurExterneAbstrait ();

    void executerProgramme ();

    Intermediaire m_intermediaire;

protected:
    string getLine ();
    void send (const string &donnees);

private:
    string m_chemin;

};

#endif // JOUEUREXTERNEABSTRAIT_HPP
