#ifndef EVENTSMANAGER_HPP
#define EVENTSMANAGER_HPP

#include <QObject>

#include "UI/WApercuPartie.hpp"
#include "UI/WidgetPartieGeneral.h"

class WApercuPartie;
class WidgetPartieGeneral;


class EventsManager : public QObject
{
    Q_OBJECT

public:

    static EventsManager* getInstance ();

    void add (const WApercuPartie *wApercuPartie);
    void remove (const WApercuPartie *wApercuPartie);

    void add (WidgetPartieGeneral *wPartie);
    void remove (WidgetPartieGeneral *wPartie);


public slots:

    void showGame (std::shared_ptr<const PartieDecrite> partie);


private:

    EventsManager ();
    EventsManager (const EventsManager &) = delete;
    void operator= (const EventsManager &) = delete;


    WidgetPartieGeneral *m_widgetPartie;

};

#endif // EVENTSMANAGER_HPP
