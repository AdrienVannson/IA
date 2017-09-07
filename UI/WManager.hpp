#ifndef WMANAGER_HPP
#define WMANAGER_HPP

#include <QIntValidator>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QToolButton>
#include <QPushButton>

#include <utility>

#include "Manager.hpp"
#include "WManagerQWidget.hpp"



template<class T, class WT> // La classe à gérer, et un widget représentant cette classe
class WManager : public WManagerQWidget
{

public:

    explicit WManager (QWidget *parent=0);

    void setManager (const Manager<T> *manager);

    void actualiser ();


private:

    const Manager<T> *m_manager;

    QLineEdit *m_champPremierAffiche;
    QLineEdit *m_champNbAffiches;
    QVBoxLayout *m_layout;
    QVBoxLayout *m_layoutLignes;

};


#include "WManager.tpp"

#endif // WMANAGER_HPP
