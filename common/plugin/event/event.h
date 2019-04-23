#ifndef EVENT_DEFS_H
#define EVENT_DEFS_H

#include "../plugin.h"

struct Event {
    PluginId    pluginId;
    EventId     eventId;
    QVariantMap args;

    /**
     * @brief Event Default Constructor
     */
    Event(void) {}

    /**
     * @brief Event Constructor
     * @param eId { eventId } - Id of the event
     */
    Event(EventId eId): eventId(eId) {
        pluginId = static_cast<PluginId>(GET_PLUGIN_ID_FROM_ENUM(eId));
    }

    /**
     * @brief setEventId - Store the id of the event
     * @param id { eventId } - Id of the event
     * @return { Event* } instance of the event builder
     */
    Event& setEventId(EventId id) {
        eventId = id;
        pluginId = static_cast<PluginId>(GET_PLUGIN_ID_FROM_ENUM(id));
        return *this;
    }

    /**
     * @brief addArg - Store argument in the event
     * @param key - { QString } The name of the argument
     * @param value - { QVariant } The argument content
     * @return { Event* } instance of the event builder
     */
    Event& addArg(const QString& key, const QVariant& value) {
        if (!key.isEmpty() && !args.contains(key)) {
            args.insert(key, value);
        }
        return *this;
    }

    /**
     * @brief hasArgs Returns if the map contains items
     * @return { boolean } returning true if the map is empty; otherwise returning false
     */
    bool hasArgs() const { return !args.isEmpty(); }
};

#endif // EVENT_DEFS_H
