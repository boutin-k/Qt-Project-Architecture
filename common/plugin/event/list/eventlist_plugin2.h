#ifndef EVENTLIST_PLUGIN2_H
#define EVENTLIST_PLUGIN2_H

#include "../../plugin.h"

enum Plugin2Event {
    PLUGIN2_EVENT1 = PLUGIN_ENUMS_START_INDEX(PLUGIN2),
    PLUGIN2_EVENT2,
    PLUGIN2_EVENT3,
    PLUGIN2_EVENT4,
    PLUGIN2_EVENT5,
    PLUGIN2_EVENT6,
    // Should always beat the end of the list
    PLUGIN2_EVENT_MAX
};

enum Plugin2Data {
    PLUGIN2_DATA1 = PLUGIN_ENUMS_START_INDEX(PLUGIN2),
    PLUGIN2_DATA2,
    PLUGIN2_DATA3,
    PLUGIN2_DATA4,
    PLUGIN2_DATA5,
    PLUGIN2_DATA6,
    // Should always beat the end of the list
    PLUGIN2_DATA_MAX
};

#endif // EVENTLIST_PLUGIN2_H
