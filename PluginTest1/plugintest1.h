#ifndef PLUGINTEST1_H
#define PLUGINTEST1_H

#include <QObject>
#include <QtPlugin>

#include "common/plugin/interface.h"
#include "common/plugin/event/eventlist.h"
#include "common/macro/qthreadsafedecl.h"
#include "eventmanager.h"

class PluginTest1 : public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "IxxiTechSide.Qt.PluginInterface" FILE "data.json")
    Q_INTERFACES(PluginInterface)

public:
    /**
     * @brief Constructor
     */
    PluginTest1(void);

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
    EventManager    mEventManager;

    SHARED_DATA(date,       QString, PLUGIN1_DATA1)
    SHARED_DATA(name,       QString, PLUGIN1_DATA2)
    SHARED_DATA(age,        int,     PLUGIN1_DATA3)
    SHARED_DATA(size,       float,   PLUGIN1_DATA4)
    SHARED_DATA(isMarried,  bool,    PLUGIN1_DATA5)
};

#endif // PLUGINTEST1_H
