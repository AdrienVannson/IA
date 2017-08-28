#ifndef WAPERCUPARTIE_HPP
#define WAPERCUPARTIE_HPP

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIcon>
#include <QToolButton>

#include <memory>

#include "partie/Partie.hpp"
#include "EventsManager.hpp"


class WApercuPartie : public QWidget
{
    Q_OBJECT


public:

    explicit WApercuPartie (QWidget *parent=0);
    ~WApercuPartie ();

    void setObject (const std::shared_ptr<const Partie> &partie);


public slots:

    void emettreAfficher ();


signals:

    void show (std::shared_ptr<const Partie> partie);


private:

    std::shared_ptr<const Partie> m_partie;


};

#endif // WAPERCUPARTIE_HPP
