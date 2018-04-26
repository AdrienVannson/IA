#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <utility>
#include <vector>
#include <memory>

using namespace std;


template<class T>
class Manager
{

public:

    Manager ();
    ~Manager ();

    shared_ptr<T> add (T *object);
    shared_ptr<T> add (const shared_ptr<T> &object);
    shared_ptr<T> addCopy (const T *object);


    unsigned int size () const;

    const vector< shared_ptr<T> >& getAll () const;
    vector< shared_ptr<T> >& getAll ();

    shared_ptr<const T> get (const int pos) const;
    shared_ptr<T> get (const int pos);



private:

    vector<shared_ptr<T>> m_objects;

};


#include "Manager.tpp"

#endif // MANAGER_HPP
