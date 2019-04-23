#ifndef PLUGINTEST2_H
#define PLUGINTEST2_H

#include <QObject>
#include <QtPlugin>
#include <QThread>

#include "common/plugin/interface.h"
#include "common/plugin/event/eventlist.h"
#include "common/macro/qthreadsafedecl.h"
#include "eventmanager.h"

class PluginTest2 : public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "IxxiTechSide.Qt.PluginInterface" FILE "data.json")
    Q_INTERFACES(PluginInterface)

public:
    /**
     * @brief Constructor
     */
    PluginTest2(void);

    /**
     * @brief Initialize plugin independant application content
     * PluginInterface override
     * @param parent - PluginManager instance
     */
    void onAttach(QObject* parent = nullptr) override;

    /**
     * @brief Initialize plugin application specific content
     * PluginInterface override
     */
    void onInit(void) override;

    /**
     * @brief Free plugin content
     * PluginInterface override
     */
    void onDetach(void) override;

private:
    QThread         mThread;
    EventManager    mEventManager;

    SHARED_DATA(id, int, PLUGIN2_DATA1)
};

#endif // PLUGINTEST2_H
