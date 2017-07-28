#ifndef EVENTSMANAGER_HPP
#define EVENTSMANAGER_HPP

#include <QObject>

#include "UI/WApercuPartie.hpp"
#include "UI/WAbstractGame.hpp"

class WApercuPartie;
class WAbstractGame;


class EventsManager : public QObject
{
    Q_OBJECT

public:

    static EventsManager* getInstance ();

    void add (const WApercuPartie *wApercuPartie);
    void remove (const WApercuPartie *wApercuPartie);

    void add (WAbstractGame *wPartie);
    void remove (WAbstractGame *wPartie);


public slots:

    void showGame (std::shared_ptr<const DescribedGame> partie);


private:

    EventsManager ();
    EventsManager (const EventsManager &) = delete;
    void operator= (const EventsManager &) = delete;


    WAbstractGame *m_widgetPartie;

};

#endif // EVENTSMANAGER_HPP
