#include "Manager.hpp"

template<class T>
Manager<T>::Manager ()
{

}

template<class T>
Manager<T>::~Manager ()
{
    for (std::pair<int, T*> objet : m_objets) {
        delete objet.second;
    }
}


template<class T>
int Manager<T>::add (T* objet)
{
    int nouvelId = m_objets.empty() ? 0 : m_objets[ m_objets.size()-1 ].first+1;
    m_objets.push_back( make_pair(nouvelId, objet) );

    return nouvelId;
}

template<class T>
int Manager<T>::add (const T &objet)
{
    T* copie = new T (objet);
    return add(copie);
}


template<class T>
const T* Manager<T>::get (const int id) const
{
    return m_objets[id].second;
}

template<class T>
T* Manager<T>::get (const int id)
{
    return m_objets[id].second;
}
