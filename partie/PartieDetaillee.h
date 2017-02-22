/*
 * Partie décrite par plusieurs informations supplémentaires
 */

#ifndef PARTIEDETAILLEE_H
#define PARTIEDETAILLEE_H

#include <string>
#include <vector>

#include "Partie.h"


class PartieDetaillee
{

public:
    PartieDetaillee ();

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

#endif // PARTIEDETAILLEE_H
