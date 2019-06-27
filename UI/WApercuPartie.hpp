#ifndef WAPERCUPARTIE_HPP
#define WAPERCUPARTIE_HPP

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIcon>
#include <QToolButton>

#include <memory>

#include "Partie.hpp"

using namespace std;


class WApercuPartie : public QWidget
{
    Q_OBJECT


public:

    explicit WApercuPartie (QWidget *parent=0);
    ~WApercuPartie ();

    void setObject (const shared_ptr<const Partie> &partie);


public slots:

    void emettreAfficher ();


signals:

    void show (shared_ptr<const Partie> partie);


private:

    shared_ptr<const Partie> m_partie;


};

#endif // WAPERCUPARTIE_HPP
