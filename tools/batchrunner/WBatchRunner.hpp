#ifndef WBATCHRUNNER_HPP
#define WBATCHRUNNER_HPP

#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QIntValidator>

#include <memory>
#include <vector>

#include "UI/MainWindow.hpp"


class MainWindow;

class WBatchRunner : public QWidget
{

    Q_OBJECT

public:

    explicit WBatchRunner (MainWindow *mainWindow=0, QWidget *parent=0);


public slots:

    void lancerParties ();


protected:

    void updateJoueurs ();


private:

    MainWindow *m_mainWindow;

    // UI
    int m_nbJoueurs;

    QVBoxLayout *m_layout;
    QVBoxLayout *m_layoutJoueurs;

    std::vector<QLineEdit*> m_champsJoueurs;

    QLineEdit *m_champNbParties;
    QPushButton *m_bouttonDemarrer;


};

#endif // WBATCHRUNNER_HPP
