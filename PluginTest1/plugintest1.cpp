#include <QDebug>
#include <QTimer>
#include <QVariant>

#include "plugintest1.h"
#include "eventmanager.h"
#include "common/plugin/event/eventlist.h"

/**
 * @brief Constructor
 */
PluginTest1::PluginTest1(void)
: PluginInterface(PLUGIN1),
  mEventManager(this) {
    qDebug() << "PluginTest1 loaded !!!";
    logD("PluginTest1 loaded !!!");
}

/**
 * @brief Initialize plugin independant application content
 * @param parent - PluginManager instance
 */
void PluginTest1::onAttach(QObject* parent) {
    Q_UNUSED(parent);

    // //////////////////////////////////////////
    // Initialize shared data here !!!
    // //////////////////////////////////////////
    set_date("19-11-82");
    set_name("Ken BOUTINEAU");
    set_age(36);
    set_size(1.75);
    set_isMarried(false);

    // //////////////////////////////////////////
    // Add internal connections
    // //////////////////////////////////////////
    connect(&mEventManager, &EventManager::sendEvent, this, &PluginInterface::sendEvent);

    // //////////////////////////////////////////
    // Send plugins listener
    // //////////////////////////////////////////
    emit listenPlugin(mEventManager, PLUGIN2);
}

/**
 * @brief Initialize plugin application specific content
 */
void PluginTest1::onInit(void) {

    // TEST
    QTimer::singleShot(1000, this, [this] {
        Q_UNUSED(this)
        emit sendEvent(Event(PLUGIN1_EVENT4));

        QVariant data;
        emit getSharedData(PLUGIN2_DATA1, data);
        qDebug() << "PLUGIN2_DATA1: " << data;
    });
    // !TEST
}

/**
 * @brief Free plugin content
 */
void PluginTest1::onDetach(void) {
}
