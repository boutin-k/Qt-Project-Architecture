#include <QDebug>
#include <QDir>
#include <QList>
#include <QPluginLoader>

// Plugin interfaces
#include "common/plugin/plugin.h"
#include "common/plugin/interface.h"
#include "common/plugin/event/eventhandler.h"

#include "logger/logger.h"
#include "shareddata/shareddata.h"

#include "pluginmanager.h"

PluginManager::PluginManager(QObject *parent) : QObject(parent)
{
    // Register MetaTypes used to exchange events
    qRegisterMetaType<Event>("Event");
    qRegisterMetaType<PluginId>("PluginId");
}

PluginManager::~PluginManager(void)
{
    unloadPlugins();
}

void PluginManager::loadPlugins(void)
{
    for (uint i = 0; i < PLUGIN_MAX; i++) {
        QPluginLoader pluginLoader(PLUGIN_PATH + PLUGIN_LIST[i], this);
        QObject *plugin = pluginLoader.instance();
        if (plugin) {
            PluginInterface* pluginInstance = qobject_cast<PluginInterface *>(plugin);

            connect(pluginInstance,
                    SIGNAL(listenPlugin(const EventHandler&, const PluginId)),
                    this,
                    SLOT(addPluginListener(const EventHandler&, const PluginId)),
                    Qt::DirectConnection);

            connect(pluginInstance,
                    SIGNAL(sendEvent(const Event&)),
                    this,
                    SLOT(broadcastEvent(const Event&)));

            connect(pluginInstance,
                    SIGNAL(setSharedData(quint32, const QVariant&)),
                    this,
                    SLOT(setSharedData(quint32, const QVariant&)));

            connect(pluginInstance,
                    SIGNAL(getSharedData(quint32, QVariant&)),
                    this,
                    SLOT(getSharedData(quint32, QVariant&)),
                    Qt::DirectConnection);

            connect(pluginInstance,
                    SIGNAL(sendLog(const PluginId&, const Log::Level&, const QString&)),
                    this,
                    SLOT(sendLog(const PluginId&, const Log::Level&, const QString&)),
                    Qt::DirectConnection);

            pluginInstance->attach(this);
            pluginInstance->initialize();

            mPluginList.insert(static_cast<PluginId>(i), pluginInstance);
        }
    }
}

/**
 * @brief PluginManager::unloadPlugin
 */
void PluginManager::unloadPlugins(void)
{
    for (const PluginInterface* pluginInstance: mPluginList) {
        const_cast<PluginInterface*>(pluginInstance)->detach();
    }
}


void PluginManager::addPluginListener(const EventHandler& pListener, const PluginId pId) {
    qDebug() << "Listener added";
    mListenerList[pId].append(&pListener);
}
void PluginManager::broadcastEvent(const Event& pEvent) const {
    for (const EventHandler* handler: mListenerList[pEvent.pluginId]) {
        handler->handleEvent(pEvent);
    }
}
void PluginManager::removePluginListener(const EventHandler& pListener) {
    Q_UNUSED(pListener);
    qDebug() << "Listener removed";
}


void PluginManager::setSharedData(quint32 pKey, const QVariant& pValue) {
    SharedData::Instance().setSharedData(pKey, pValue);
}
void PluginManager::getSharedData(quint32 pKey, QVariant& pOutValue) const {
    SharedData::Instance().getSharedData(pKey, pOutValue);
}


void PluginManager::sendLog(const PluginId& pId, const Log::Level& pLevel, const QString& pMessage) {
    Log::Logger::Instance().log(PLUGIN_LIST[pId], pLevel, pMessage);
}
