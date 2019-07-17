#ifndef WABSTRACTPARTIE_HPP
#define WABSTRACTPARTIE_HPP

#include <QWidget>
#include <QTimer>

#include <memory>

#include "Partie.hpp"
#include "unused.hpp"


class WAbstractPartie : public QWidget
{
    Q_OBJECT

public:
    explicit WAbstractPartie (QWidget *parent = 0);

public slots:
    void showGame (const std::shared_ptr<const Partie> &partie);
    void tourSuivant ();

protected:
    virtual void initialiserPartie () = 0;
    virtual void afficherTourActuel () = 0;

    std::shared_ptr<const Partie> m_partie;
    int m_tourActuel;

private:
    // Timer pour passer au tour suivant
    QTimer *m_timer;

};

#endif // WABSTRACTPARTIE_HPP
