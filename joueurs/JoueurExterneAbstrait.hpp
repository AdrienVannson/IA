#ifndef JOUEUREXTERNEABSTRAIT_HPP
#define JOUEUREXTERNEABSTRAIT_HPP

#include <QProcess>

#include <string>
#include <queue>

#include "Joueur.hpp"


class Communication : public QObject
{
    Q_OBJECT

public:
    Communication (QObject *parent=0);

public slots:
    void demarrer (const std::string chemin);
    void envoyerDonnees (const std::string donnees);
    void lireDonnees ();
    void lireErreur ();
    void tuer ();

    void termine (int exitCode, QProcess::ExitStatus exitStatus);

signals:
    void donneesRecues (const std::string donnees);

public:
    QProcess *m_processus;
};


class Intermediaire : public QObject
{
    Q_OBJECT

public:
    Intermediaire (QObject *parent=0);

    void demarrer (const std::string &chemin);
    void envoyerDonnees (const std::string donnees);
    void tuer ();

    std::queue<std::string> m_lignes;

public slots:
    void recevoirDonnees (const std::string donnees);

signals:
    void debut (const std::string chemin);
    void donneesEnvoyees (const std::string donnees);
    void doitTuer ();

};


class JoueurExterneAbstrait : public Joueur
{

public:
    JoueurExterneAbstrait (const std::string chemin);
    ~JoueurExterneAbstrait ();

    void executerProgramme ();

    Intermediaire m_intermediaire;
    Communication *m_communication;

protected:
    std::string getLine ();
    void send (const std::string &donnees);

private:
    std::string m_chemin;

};

#endif // JOUEUREXTERNEABSTRAIT_HPP
