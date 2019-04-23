#ifndef EVENTLIST_PLUGIN1_H
#define EVENTLIST_PLUGIN1_H

#include "../../plugin.h"

enum Plugin1Event {
    PLUGIN1_EVENT1 = PLUGIN_ENUMS_START_INDEX(PLUGIN1),
    PLUGIN1_EVENT2,
    PLUGIN1_EVENT3,
    PLUGIN1_EVENT4,
    PLUGIN1_EVENT5,
    PLUGIN1_EVENT6,
    // Should always beat the end of the list
    PLUGIN1_EVENT_MAX
};

enum Plugin1Data {
    PLUGIN1_DATA1 = PLUGIN_ENUMS_START_INDEX(PLUGIN1),
    PLUGIN1_DATA2,
    PLUGIN1_DATA3,
    PLUGIN1_DATA4,
    PLUGIN1_DATA5,
    PLUGIN1_DATA6,
    // Should always beat the end of the list
    PLUGIN1_DATA_MAX
};

#endif // EVENTLIST_PLUGIN1_H
