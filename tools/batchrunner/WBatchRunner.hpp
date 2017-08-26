#ifndef WBATCHRUNNER_HPP
#define WBATCHRUNNER_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QProgressBar>

#include <memory>
#include <vector>

#include "partie/Joueur/Joueur.hpp"


class WBatchRunner : public QWidget
{

    Q_OBJECT

public:

    explicit WBatchRunner (QWidget *parent=0);


private:

    QPushButton *m_startButton;
    QProgressBar *m_progressBar;


};

#endif // WBATCHRUNNER_HPP
