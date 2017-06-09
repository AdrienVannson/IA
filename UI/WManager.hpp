#ifndef WMANAGER_HPP
#define WMANAGER_HPP

#include <QWidget>

#include "Manager.hpp"


template<class T, class WT> // La classe à gérer, et un widget représentant cette classe
class WManager : public QWidget
{

public:

    explicit WManager (QWidget *parent=0);

    void setManager (const Manager<T> *manager);


private:

    const Manager<T> *m_manager;

};


#include "WManager.tpp"

#endif // WMANAGER_HPP
