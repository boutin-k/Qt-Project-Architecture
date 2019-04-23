#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QObject>
#include <QList>

#include "common/logger/defs.h"
#include "common/plugin/plugin.h"
#include "common/plugin/event/event.h"

class PluginInterface;
class EventHandler;

class PluginManager : public QObject
{
    Q_OBJECT

public:
    explicit PluginManager(QObject *parent = nullptr);
    ~PluginManager();

    void loadPlugins(void);
    void unloadPlugins(void);

signals:

public slots:
    void addPluginListener(const EventHandler& listener, const PluginId id);
    void removePluginListener(const EventHandler& listener);
    void broadcastEvent(const Event& event) const;

    void setSharedData(quint32 pKey, const QVariant& pValue);
    void getSharedData(quint32 pKey, QVariant& pOutValue) const;

    void sendLog(const PluginId& pId, const Log::Level& pLevel, const QString& pMessage);

private:
    QList<const EventHandler*>              mListenerList[PLUGIN_MAX];
    QMap<PluginId, const PluginInterface*>  mPluginList;
};

#endif // PLUGINMANAGER_H
