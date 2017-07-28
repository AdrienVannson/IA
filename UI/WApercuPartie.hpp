#ifndef WAPERCUPARTIE_HPP
#define WAPERCUPARTIE_HPP

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIcon>
#include <QToolButton>

#include <memory>

#include "partie/DescribedGame.hpp.h"
#include "EventsManager.hpp"


class WApercuPartie : public QWidget
{
    Q_OBJECT


public:

    explicit WApercuPartie (QWidget *parent=0);
    ~WApercuPartie ();

    void setObject (const std::shared_ptr<const DescribedGame> &partie);


public slots:

    void emettreAfficher ();


signals:

    void show (std::shared_ptr<const DescribedGame> partie);


private:

    std::shared_ptr<const DescribedGame> m_partie;


};

#endif // WAPERCUPARTIE_HPP
