#ifndef WAPERCUPARTIE_HPP
#define WAPERCUPARTIE_HPP

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIcon>
#include <QToolButton>

#include <memory>

#include "partie/PartieDecrite.h"


class WApercuPartie : public QWidget
{
    Q_OBJECT


public:

    explicit WApercuPartie (QWidget *parent=0);

    void setObject (const std::shared_ptr<const PartieDecrite> &partie);


public slots:

    void emettreAfficher ();


signals:

    void afficher (std::shared_ptr<const PartieDecrite> partie);


private:

    std::shared_ptr<const PartieDecrite> m_partie;


};

#endif // WAPERCUPARTIE_HPP
