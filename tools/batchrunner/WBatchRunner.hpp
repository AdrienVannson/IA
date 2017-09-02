#ifndef WBATCHRUNNER_HPP
#define WBATCHRUNNER_HPP

#include <QVBoxLayout>
#include <QPushButton>
#include <QProgressBar>
#include <QLineEdit>
#include <QIntValidator>

#include <memory>
#include <vector>


class WBatchRunner : public QWidget
{

    Q_OBJECT

public:

    explicit WBatchRunner (QWidget *parent=0);


protected:

    void updateJoueurs ();


private:

    QVBoxLayout *m_layout;
    QVBoxLayout *m_layoutJoueurs;

    int m_nbJoueurs;

    std::vector<QLineEdit*> m_champsJoueurs;

    QPushButton *m_bouttonDemarrer;
    QProgressBar *m_barreProgression;


};

#endif // WBATCHRUNNER_HPP
