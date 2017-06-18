#ifndef WGAMERUNNER_HPP
#define WGAMERUNNER_HPP

#include <QWidget>

#include "GameRunner.hpp"


class WGameRunner : public QWidget
{
    Q_OBJECT

public:

    explicit WGameRunner (GameRunner *gameRunnner, QWidget *parent=0);


private:

    GameRunner *m_gameRunner;

};

#endif // WGAMERUNNER_HPP
