#ifndef PLAYERFACTORY_HPP
#define PLAYERFACTORY_HPP

#include <memory>

#include "Joueur.hpp"

using namespace std;


class JoueurFactory
{

public:

    JoueurFactory (const string &nom="");

    virtual shared_ptr<Joueur> getNewPlayer () const = 0;

    string nom () const;
    void setNom (const string &nouveauNom);


private:

    string m_nom;

};

#endif // PLAYERFACTORY_HPP
