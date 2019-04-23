#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include "event.h"

class EventHandler : public QObject {
    Q_OBJECT

public:
    EventHandler(QObject* parent = nullptr) : QObject(parent) {}
    EventHandler(const EventHandler &) : QObject(nullptr) {}
    virtual ~EventHandler() {}

public slots:
    virtual void handleEvent(const Event& ev) const = 0;

signals:
    void sendEvent(const Event&) const;
};

#endif // EVENTHANDLER_H
