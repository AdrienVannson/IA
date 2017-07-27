#include "GameRunnerThread.hpp"

GameRunnerThread::GameRunnerThread (QObject *parent) :
    QThread (parent)
{
}

void GameRunnerThread::setPlayers (const std::vector< std::shared_ptr<Player> > &players)
{
    m_players = players;
}

void GameRunnerThread::run ()
{
    for (std::shared_ptr<Player> &player : m_players) {
        player->startGame();
    }


    GameSituation situationDepart;

    /* Wondev-Woman

    situationDepart.m_taille = 5 + rand()%3;

    for (int iLigne=0; iLigne<GameSituation::TAILLE_MAX; iLigne++) {
        for (int iColonne=0; iColonne<GameSituation::TAILLE_MAX; iColonne++) {

            if (iLigne >= situationDepart.m_taille || iColonne >= situationDepart.m_taille) {
                situationDepart.m_hauteursCellules[iLigne][iColonne] = GameSituation::HAUTEUR_MAX_CELLULE+1;
            }

        }
    }


    for (unsigned int iPlayer=0; iPlayer<m_players.size(); iPlayer++) {

        for (int iUnite=0; iUnite<GameSituation::NB_UNITES_JOUEUR; iUnite++) {

            int iLigne, iColonne;
            bool estValide;

            do {
                iLigne = rand() % situationDepart.m_taille;
                iColonne = rand() % situationDepart.m_taille;

                estValide = true;

                for (unsigned int iJoueurVerifie=0; iJoueurVerifie<=iPlayer; iJoueurVerifie++) {

                    for (int iUniteVerifiee=0;
                         iUniteVerifiee<iUnite || (iUniteVerifiee<GameSituation::NB_UNITES_JOUEUR && iJoueurVerifie<iPlayer);
                         iUniteVerifiee++) {

                        if (situationDepart.m_positionsJoueurs[iJoueurVerifie][iUniteVerifiee].first == iLigne
                         && situationDepart.m_positionsJoueurs[iJoueurVerifie][iUniteVerifiee].second == iColonne) {

                            estValide = false;
                            break;
                        }
                    }
                }

            } while (!estValide);

            situationDepart.m_positionsJoueurs[iPlayer][iUnite] = std::make_pair(iLigne, iColonne);

        }
    }*/


    Game *partie = SimulateurPartie::simulerPartie(situationDepart, m_players);


    for (std::shared_ptr<Player> &player : m_players) {
        player->endGame();
    }

    emit (simulationDone( std::shared_ptr<Game>(partie) ));
}
