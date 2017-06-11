#ifndef WAPERCUPARTIE_HPP
#define WAPERCUPARTIE_HPP

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIcon>
#include <QToolButton>

#include "partie/Partie.h"


class WApercuPartie : public QWidget
{
    Q_OBJECT


public:

    explicit WApercuPartie (QWidget *parent=0);

    void setObjet (const Partie *partie);


public slots:

    void emettreAfficher ();


signals:

    void afficher (const Partie *partie);


private:

    const Partie *m_partie;


};

#endif // WAPERCUPARTIE_HPP
