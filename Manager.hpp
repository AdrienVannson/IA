#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <utility>
#include <vector>
#include <memory>


template<class T>
class Manager
{

public:

    Manager ();
    ~Manager ();

    std::shared_ptr<T> add (T *object);
    std::shared_ptr<T> add (const std::shared_ptr<T> &object);
    std::shared_ptr<T> addCopy (const T *object);


    unsigned int size () const;

    const std::vector< std::shared_ptr<T> >& getAll () const;
    std::vector< std::shared_ptr<T> >& getAll ();

    std::shared_ptr<const T> get (const int pos) const;
    std::shared_ptr<T> get (const int pos);



private:

    std::vector< std::shared_ptr<T> > m_objects;

};


#include "Manager.tpp"

#endif // MANAGER_HPP
