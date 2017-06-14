#ifndef WAPERCUPARTIE_HPP
#define WAPERCUPARTIE_HPP

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIcon>
#include <QToolButton>

#include "partie/PartieDecrite.h"


class WApercuPartie : public QWidget
{
    Q_OBJECT


public:

    explicit WApercuPartie (QWidget *parent=0);

    void setObjet (const PartieDecrite *partie);


public slots:

    void emettreAfficher ();


signals:

    void afficher (const PartieDecrite *partie);


private:

    const PartieDecrite *m_partie;


};

#endif // WAPERCUPARTIE_HPP
