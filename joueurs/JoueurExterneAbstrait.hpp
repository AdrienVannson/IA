#ifndef JOUEUREXTERNEABSTRAIT_HPP
#define JOUEUREXTERNEABSTRAIT_HPP

#include <QApplication>
#include <QProcess>
#include <QEventLoop>

#include <iostream>
#include <string>

#include "partie/Joueur/Joueur.hpp"

using namespace std;


class Intermediaire : public QObject
{
    Q_OBJECT

public:
    Intermediaire (QObject *parent=0);

    void envoyerDonnees (const string donnees);
    void lire ();

    string m_donnees;

public slots:
    void recevoirDonnees (const string donnees);

signals:
    void donneesEnvoyees (const string donnees);
    void doitLire ();

};


class JoueurExterneAbstrait : public Joueur
{

public:
    JoueurExterneAbstrait ();
    ~JoueurExterneAbstrait ();

    Intermediaire m_intermediaire;

protected:
    string getLine ();
    void send (const string &donnees);

};

#endif // JOUEUREXTERNEABSTRAIT_HPP
