#include "EventsManager.hpp"


EventsManager* EventsManager::getInstance ()
{
    static EventsManager instance;
    return &instance;
}


void EventsManager::add (const WApercuPartie *wApercuPartie)
{
    connect(wApercuPartie, &WApercuPartie::show, this, &EventsManager::showGame);
}

void EventsManager::remove (const WApercuPartie *wApercuPartie)
{

}


void EventsManager::showGame (std::shared_ptr<const PartieDecrite> partie)
{

}
