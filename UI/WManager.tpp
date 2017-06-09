#include "WManager.hpp"

template<class T, class WV>
WManager<T, WV>::WManager (QWidget *parent) :
    QWidget (parent),
    m_manager (0)
{

}

template<class T, class WT>
void WManager<T, WT>::setManager (const Manager<T> *manager)
{
    m_manager = manager;
}
