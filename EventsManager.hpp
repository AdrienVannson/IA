#ifndef EVENTSMANAGER_HPP
#define EVENTSMANAGER_HPP

#include <QObject>

#include "UI/WApercuPartie.hpp"
#include "UI/WAbstractPartie.hpp"

class WApercuPartie;
class WAbstractPartie;


class EventsManager : public QObject
{
    Q_OBJECT

public:

    EventsManager ();


    void add (const WApercuPartie *wApercuPartie);
    void remove (const WApercuPartie *wApercuPartie);

    void add (WAbstractPartie *wPartie);
    void remove (WAbstractPartie *wPartie);


public slots:

    void showGame (std::shared_ptr<const Partie> partie);


private:

    WAbstractPartie *m_widgetPartie;

};

#endif // EVENTSMANAGER_HPP
