#include "WBatchRunner.hpp"

WBatchRunner::WBatchRunner(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;
    setLayout(layout);

    m_startButton = new QPushButton("Start");
    layout->addWidget(m_startButton);

    m_progressBar = new QProgressBar;
    m_progressBar->setValue(42);
    layout->addWidget(m_progressBar);
}

void WBatchRunner::addPlayer (const std::shared_ptr<Joueur> &player)
{
    m_players.push_back(player);
}
