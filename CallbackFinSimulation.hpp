#ifndef CALLBACKFINSIMULATION_HPP
#define CALLBACKFINSIMULATION_HPP

#include <memory>

#include "partie/Partie.hpp"
#include "unused.hpp"


class CallbackFinSimulation
{

public:

    CallbackFinSimulation ();
    virtual ~CallbackFinSimulation ();


    virtual void operator() (const std::shared_ptr<Partie> &partie);


};

#endif // CALLBACKFINSIMULATION_HPP
