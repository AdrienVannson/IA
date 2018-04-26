#ifndef JOUEUREXTERNEABSTRAIT_HPP
#define JOUEUREXTERNEABSTRAIT_HPP

#include <QApplication>
#include <QProcess>
#include <QEventLoop>

#include <string>

#include "partie/Joueur/Joueur.hpp"

using namespace std;


class Intermediaire : public QObject
{
    Q_OBJECT

public:
    Intermediaire (QObject *parent=0);

    void demarrer (const string &chemin);
    void envoyerDonnees (const string donnees);
    void lire ();
    void tuer ();

    string m_donnees;

public slots:
    void recevoirDonnees (const string donnees);

signals:
    void debut (const string chemin);
    void donneesEnvoyees (const string donnees);
    void doitLire ();
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
