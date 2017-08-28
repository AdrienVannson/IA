#ifndef PLAYERFACTORY_HPP
#define PLAYERFACTORY_HPP

#include <memory>

#include "Joueur.hpp"


class JoueurFactory
{

public:

    JoueurFactory (const std::string &nom="");

    virtual std::shared_ptr<Joueur> getNewPlayer () const = 0;

    std::string nom () const;
    void setNom (const std::string &nouveauNom);


private:

    std::string m_nom;

};

#endif // PLAYERFACTORY_HPP
