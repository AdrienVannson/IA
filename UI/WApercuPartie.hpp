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

public:

    explicit WApercuPartie (QWidget *parent=0);

    void setObjet (const Partie *partie);


};

#endif // WAPERCUPARTIE_HPP
