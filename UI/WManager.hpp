#ifndef WMANAGER_HPP
#define WMANAGER_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QToolButton>

#include <utility>

#include "Manager.hpp"


template<class T, class WT> // La classe à gérer, et un widget représentant cette classe
class WManager : public QWidget
{

public:

    explicit WManager (QWidget *parent=0);

    void setManager (const Manager<T> *manager);

    void actualiser ();


private:

    const Manager<T> *m_manager;

    QVBoxLayout *m_layout;
    QVBoxLayout *m_layoutLignes;

};


#include "WManager.tpp"

#endif // WMANAGER_HPP
