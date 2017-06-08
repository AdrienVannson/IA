#ifndef JOUERPARTIEWIDGET_H
#define JOUERPARTIEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "partie/SimulateurPartie.h"
#include "partie/JoueursManager.h"
#include "partie/PartiesManager.h"


class WJouerPartie : public QWidget
{

public:

    explicit WJouerPartie (JoueursManager *joueurManager, PartiesManager *partiesManager, QWidget *parent = 0);


public slots:

    void simulerPartie ();


private:

    JoueursManager *m_joueursManager;
    PartiesManager *m_partiesManager;

    QLineEdit *m_saisieID1;
    QLineEdit *m_saisieID2;

};

#endif // JOUERPARTIEWIDGET_H
