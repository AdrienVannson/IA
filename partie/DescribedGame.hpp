/*
 * Partie décrite par plusieurs informations supplémentaires
 */

#ifndef DESCRIBEDGAME_HPP
#define DESCRIBEDGAME_HPP

#include <string>
#include <vector>

#include "Game.hpp"


class DescribedGame : public Game
{

public:

    DescribedGame ();
    DescribedGame (const Game &partie);

    int id () const;

    std::vector<int> idsIAs () const;
    void setIdsIAs (std::vector<int> nouveauIdsIAs);

    std::string commentaire () const;
    void setCommentaire (const std::string &nouveauCommentaire);



private:
    static int m_idSuivant;

    // Identifiant (unique) de la partie
    int m_id;

    // IDs des IAs ayant participé à la partie
    std::vector<int> m_idsIAs;

    // Commentaire sur la partie (facilite le débuggage)
    std::string m_commentaire;

};

#endif // DESCRIBEDGAME_HPP
