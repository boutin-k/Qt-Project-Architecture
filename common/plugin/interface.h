#ifndef PLUGIN_INTERFACE_H
#define PLUGIN_INTERFACE_H

#include <QtPlugin>
#include "plugin.h"
#include "event/eventhandler.h"

#include "../logger/defs.h"

class PluginInterface: public QObject
{
    Q_OBJECT

public:
    /**
     * @brief PluginInterface constructor
     * Connect internal signals/slots to guarantee thread safe call
     */
    PluginInterface(PluginId pId) : QObject(nullptr), mPluginId(pId) {
        connect(this, &PluginInterface::requestAttach,
                this, &PluginInterface::onAttach,
                Qt::QueuedConnection);

        connect(this, &PluginInterface::requestInit,
                this, &PluginInterface::onInit,
                Qt::QueuedConnection);

        connect(this, &PluginInterface::requestDetach,
                this, &PluginInterface::onDetach,
                Qt::QueuedConnection);
    }

    /**
     * @brief PluginInterface destructor
     * Disconnect internal signals/slots
     */
    virtual ~PluginInterface() { disconnect(); }

    /**
     * @brief Thread safe onAttach function caller
     * This function could not be override {final}
     * @param parent - PluginManager instance
     */
    inline virtual void attach(QObject* parent = nullptr) final {
        emit requestAttach(parent);
    }

    /**
     * @brief Thread safe onInit function caller
     * This function could not be override {final}
     */
    inline virtual void initialize(void) final {
        emit requestInit();
    }

    /**
     * @brief Thread safe onDetach function caller
     * This function could not be override {final}
     */
    inline virtual void detach(void) final {
        emit requestDetach();
    }

public slots:
    /**
     * @brief [Async call] Initialize plugin independant application content
     * Pure virtual function. It must be override
     * @param parent - PluginManager instance
     */
    virtual void onAttach(QObject* parent = nullptr) = 0;

    /**
     * @brief [Async call] Initialize plugin application specific content
     * Pure virtual function. It must be override
     */
    virtual void onInit(void) = 0;

    /**
     * @brief [Async call] Free plugin content
     * Pure virtual function. It must be override
     */
    virtual void onDetach(void) = 0;

signals:
    // //////////////////////////////////////////
    // Direction: From main controller to plugin
    // //////////////////////////////////////////
    void requestAttach(QObject* parent = nullptr);
    void requestInit(void);
    void requestDetach(void);

    // //////////////////////////////////////////
    // Direction: From plugin to main controller
    // //////////////////////////////////////////
    void listenPlugin(const EventHandler& handler, const PluginId id);
    void sendEvent(const Event&) const;

    void setSharedData(quint32 pKey, const QVariant& pValue);
    void getSharedData(quint32 pKey, QVariant& pOutValue);

    void sendLog(const PluginId& pId, const Log::Level& pLevel, const QString& pMessage);

protected:
    virtual void logV(const QString& pMessage) final {
        emit sendLog(mPluginId, Log::Verbose, pMessage);
    }
    virtual void logD(const QString& pMessage) final {
        emit sendLog(mPluginId, Log::Debug, pMessage);
    }
    virtual void logI(const QString& pMessage) final {
        emit sendLog(mPluginId, Log::Info, pMessage);
    }
    virtual void logW(const QString& pMessage) final {
        emit sendLog(mPluginId, Log::Warning, pMessage);
    }
    virtual void logE(const QString& pMessage) final {
        emit sendLog(mPluginId, Log::Error, pMessage);
    }
    virtual void logWtf(const QString& pMessage) final {
        emit sendLog(mPluginId, Log::Assert, pMessage);
    }

private:
    PluginId    mPluginId;
};

#define PluginInterface_iid "IxxiTechSide.Qt.PluginInterface"
Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)

#endif // PLUGIN_INTERFACE_H
