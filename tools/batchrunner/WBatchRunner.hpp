#ifndef WBATCHRUNNER_HPP
#define WBATCHRUNNER_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QProgressBar>

#include <memory>
#include <vector>

#include "partie/Joueur/Player.hpp"


class WBatchRunner : public QWidget
{

    Q_OBJECT

public:

    explicit WBatchRunner (QWidget *parent=0);

    void addPlayer (const std::shared_ptr<Player> &player);


private:

    std::vector< std::shared_ptr<Player> > m_players;

    QPushButton *m_startButton;
    QProgressBar *m_progressBar;


};

#endif // WBATCHRUNNER_HPP
