#ifndef EVENTSMANAGER_HPP
#define EVENTSMANAGER_HPP

#include <QObject>

#include "UI/WApercuPartie.hpp"

class WApercuPartie;


class EventsManager : public QObject
{
    Q_OBJECT

public:

    static EventsManager* getInstance ();

    void add (const WApercuPartie *wApercuPartie);
    void remove (const WApercuPartie *wApercuPartie);


public slots:

    void showGame (std::shared_ptr<const PartieDecrite> partie);


private:

    EventsManager () {}
    EventsManager (const EventsManager &) = delete;
    void operator= (const EventsManager &) = delete;

};

#endif // EVENTSMANAGER_HPP
