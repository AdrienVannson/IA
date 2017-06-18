#include "Manager.hpp"

template<class T>
Manager<T>::Manager ()
{
}

template<class T>
Manager<T>::~Manager ()
{
}


template<class T>
std::shared_ptr<T> Manager<T>::add (T* object)
{
    m_objects.push_back( std::shared_ptr<T> (object) );
    return m_objects[ m_objects.size()-1 ];
}

template<class T>
std::shared_ptr<T> Manager<T>::add (const std::shared_ptr<T> &object)
{
    m_objects.push_back(object);
    return m_objects[ m_objects.size()-1 ];
}

template<class T>
std::shared_ptr<T> Manager<T>::addCopy (const T* object)
{
    T* copy = new T (*object);
    return add(copy);
}


template<class T>
const std::vector< std::shared_ptr<T> >* Manager<T>::getAll () const
{
    return &m_objects;
}

template<class T>
std::shared_ptr<const T> Manager<T>::get (const int pos) const
{
    return m_objects[pos];
}

template<class T>
std::shared_ptr<T> Manager<T>::get (const int pos)
{
    return m_objects[pos];
}
