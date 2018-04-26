#ifndef CALLBACKFINSIMULATION_HPP
#define CALLBACKFINSIMULATION_HPP

#include <memory>

#include "partie/Partie.hpp"
#include "unused.hpp"

using namespace std;


class CallbackFinSimulation
{

public:

    CallbackFinSimulation ();
    virtual ~CallbackFinSimulation ();


    virtual void operator() (const shared_ptr<Partie> &partie);


};

#endif // CALLBACKFINSIMULATION_HPP
