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

    situationDepart.m_taille = 4;
    situationDepart.m_nbUnitesJoueur = 2;

    for (unsigned int iPlayer=0; iPlayer<m_players.size(); iPlayer++) {

        for (int iUnite=0; iUnite<situationDepart.m_nbUnitesJoueur; iUnite++) {

            int iLigne, iColonne;
            bool estValide;

            do {
                iLigne = rand() % situationDepart.m_taille;
                iColonne = rand() % situationDepart.m_taille;

                estValide = true;

                for (unsigned int iJoueurVerifie=0; iJoueurVerifie<=iPlayer; iJoueurVerifie++) {
                    for (int iUniteVerifiee=0; iUniteVerifiee<iUnite || iJoueurVerifie<iPlayer; iUniteVerifiee++) {
                        if (situationDepart.m_positionsJoueurs[iJoueurVerifie][iUniteVerifiee].first == iLigne
                         || situationDepart.m_positionsJoueurs[iJoueurVerifie][iUniteVerifiee].second == iColonne) {

                            estValide = false;
                            break;
                        }
                    }
                }

            } while (!estValide);

        }
    }


    Game *partie = SimulateurPartie::simulerPartie(situationDepart, m_players);


    for (std::shared_ptr<Player> &player : m_players) {
        player->endGame();
    }

    emit (simulationDone( std::shared_ptr<Game>(partie) ));
}
