#include "GameRunner.hpp"

GameRunner::GameRunner()
{

}

void GameRunner::runGame (std::vector< std::shared_ptr<Player> > &players)
{
    for (std::shared_ptr<Player> &player : players) {
        player->startGame();
    }


    SituationJeu situationDepart (players.size());

    for (unsigned int iPlayer=0; iPlayer<players.size(); iPlayer++) {
        situationDepart.setPositionJoueur(iPlayer, rand()%(SituationJeu::NB_CELLULES));
    }


    Partie *partie = SimulateurPartie::simulerPartie(situationDepart, players);
    std::shared_ptr<PartieDecrite> partieDecrite (new PartieDecrite(*partie));
    delete partie;


    for (std::shared_ptr<Player> &player : players) {
        player->endGame();
    }

    emit gameRunned(partieDecrite);
}
