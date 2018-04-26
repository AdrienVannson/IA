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
shared_ptr<T> Manager<T>::add (T* object)
{
    m_objects.push_back( shared_ptr<T> (object) );
    return m_objects[ m_objects.size()-1 ];
}

template<class T>
shared_ptr<T> Manager<T>::add (const shared_ptr<T> &object)
{
    m_objects.push_back(object);
    return m_objects[ m_objects.size()-1 ];
}

template<class T>
shared_ptr<T> Manager<T>::addCopy (const T* object)
{
    T* copy = new T (*object);
    return add(copy);
}


template<class T>
unsigned int Manager<T>::size () const
{
    return m_objects.size();
}

template<class T>
const vector< shared_ptr<T> >& Manager<T>::getAll () const
{
    return m_objects;
}

template<class T>
vector< shared_ptr<T> >& Manager<T>::getAll ()
{
    return m_objects;
}

template<class T>
shared_ptr<const T> Manager<T>::get (const int pos) const
{
    return m_objects[pos];
}

template<class T>
shared_ptr<T> Manager<T>::get (const int pos)
{
    return m_objects[pos];
}
