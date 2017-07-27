#ifndef WGAMERUNNER_HPP
#define WGAMERUNNER_HPP

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

#include "GameRunner.hpp"


class WGameRunner : public QWidget
{
    Q_OBJECT

public:

    explicit WGameRunner (GameRunner *gameRunnner, QWidget *parent=0);


public slots:

    void updateCount ();


private:

    GameRunner *m_gameRunner;

    QLabel *m_label;

};

#endif // WGAMERUNNER_HPP
