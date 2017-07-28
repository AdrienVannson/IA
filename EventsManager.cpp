#include "EventsManager.hpp"

EventsManager::EventsManager () :
    m_widgetPartie (0)
{
}

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
    disconnect(wApercuPartie, &WApercuPartie::show, this, &EventsManager::showGame);
}


void EventsManager::add (WidgetPartieGeneral *wPartie)
{
    m_widgetPartie = wPartie;
}

void EventsManager::remove (WidgetPartieGeneral *wPartie)
{
    if (wPartie == m_widgetPartie) {
        m_widgetPartie = 0;
    }
}


void EventsManager::showGame (std::shared_ptr<const DescribedGame> partie)
{
    if (m_widgetPartie != 0) {
        m_widgetPartie->showGame(partie);
    }
}
