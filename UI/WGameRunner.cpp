#include "WGameRunner.hpp"

WGameRunner::WGameRunner (GameRunner *gameRunnner, QWidget *parent) :
    QWidget (parent),
    m_gameRunner (gameRunnner)
{
    QVBoxLayout *layout = new QVBoxLayout;
    setLayout(layout);

    m_label = new QLabel;
    layout->addWidget(m_label);

    connect(m_gameRunner, &GameRunner::updated, this, &WGameRunner::updateCount);

    updateCount();
}

void WGameRunner::updateCount ()
{
    m_label->setText(QString::number(m_gameRunner->nbPendingGames()));
}
