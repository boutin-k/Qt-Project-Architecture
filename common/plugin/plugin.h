#ifndef PLUGIN_DEFS_H
#define PLUGIN_DEFS_H

#include <QVariant>

using EventId = quint32;
using DataId  = quint32;
Q_DECLARE_METATYPE(DataId)

//using Callback = std::function<void(QVariant)>;
//Q_DECLARE_METATYPE(Callback)

// Macro used to define the first index of pluginEvent enums and pluginData enums
#define PLUGIN_START_INDEX_FACTOR           1000
#define PLUGIN_ENUMS_START_INDEX(PLUGIN_ID) (PLUGIN_ID * PLUGIN_START_INDEX_FACTOR + 1)
#define GET_PLUGIN_ID_FROM_ENUM(ENUM)       (ENUM / PLUGIN_START_INDEX_FACTOR)

enum PluginId {
    PLUGIN1,
    PLUGIN2,
    // Should always beat the end of the list
    PLUGIN_MAX
};
Q_DECLARE_METATYPE(PluginId)

static const QString PLUGIN_LIST[PLUGIN_MAX] = {
    "PluginTest1",
    "PluginTest2"
};

#define PLUGIN_PATH "/home/ken/workspace/Reload/plugins/"

#endif // PLUGIN_DEFS_H
