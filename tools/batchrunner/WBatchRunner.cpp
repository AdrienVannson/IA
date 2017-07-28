#include "WBatchRunner.hpp"

WBatchRunner::WBatchRunner(QWidget *parent) :
    QWidget(parent)
{

}

void WBatchRunner::addPlayer (const std::shared_ptr<Player> &player)
{
    m_players.push_back(player);
}
