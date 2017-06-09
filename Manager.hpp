#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <utility>
#include <vector>


template<class T>
class Manager
{

public:
    Manager ();
    ~Manager ();

    int add (T* objet);
    int add (const T &objet);

    const std::vector< std::pair<int, T*> >* getObjets () const;

    const T* get (const int id) const;
    T* get (const int id);



private:

    std::vector< std::pair<int, T*> > m_objets; // ID, pointeur vers l'objet

};


#include "Manager.tpp"

#endif // MANAGER_HPP
