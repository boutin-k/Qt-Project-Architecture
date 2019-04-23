#include <QtDebug>

#include "eventmanager.h"
#include "../common/plugin/event/event.h"
#include "../common/plugin/event/eventlist.h"

EventManager::EventManager(QObject *parent) : EventHandler(parent)
{
    setParent(parent);
}

EventManager::~EventManager(void)
{
}

void EventManager::handleEvent(const Event& ev) const {
    switch (ev.pluginId) {
        case PLUGIN1: handlePlugin1Event(ev); break;
        case PLUGIN2: handlePlugin2Event(ev); break;
        default:
        break;
    }
}

void EventManager::handlePlugin1Event(const Event& ev) const {
    switch (ev.eventId) {
        case PLUGIN1_EVENT1: break;
        case PLUGIN1_EVENT2: break;
        case PLUGIN1_EVENT3: break;
        case PLUGIN1_EVENT4:
            qDebug() << "Receive event4 from plugin1";
            break;
        case PLUGIN1_EVENT5: break;
        case PLUGIN1_EVENT6: break;
        default: break;
    }
}

void EventManager::handlePlugin2Event(const Event& ev) const {
    switch (ev.eventId) {
        case PLUGIN2_EVENT1: break;
        case PLUGIN2_EVENT2: break;
        case PLUGIN2_EVENT3: break;
        case PLUGIN2_EVENT4: break;
        case PLUGIN2_EVENT5: break;
        case PLUGIN2_EVENT6: break;
        default: break;
    }
}
