#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <QObject>
#include "common/plugin/event/eventhandler.h"

class EventManager: public EventHandler
{
    Q_OBJECT

public:
    EventManager(QObject *parent = nullptr);
    ~EventManager(void) override;

    void handleEvent(const Event& ev) const override;

private:
    void handlePlugin1Event(const Event& ev) const;
    void handlePlugin2Event(const Event& ev) const;
};

#endif // EVENTMANAGER_H
