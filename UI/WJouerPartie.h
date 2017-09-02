#ifndef JOUERPARTIEWIDGET_H
#define JOUERPARTIEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "partie/simulerPartie.hpp"


class WJouerPartie : public QWidget
{

public:

    explicit WJouerPartie (QWidget *parent = 0);


public slots:

    void simulerPartie ();


private:

    /*JoueursManager *m_joueursManager;
    PartiesManager *m_partiesManager;*/

    QLineEdit *m_saisieID1;
    QLineEdit *m_saisieID2;

};

#endif // JOUERPARTIEWIDGET_H
