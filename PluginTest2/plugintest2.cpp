#include <QDebug>
#include <QVariant>
#include "plugintest2.h"
#include "common/plugin/event/eventlist.h"

#include <QTimer>

/**
 * @brief Constructor
 */
PluginTest2::PluginTest2(void)
: PluginInterface(PLUGIN2),
  mThread(nullptr),
  mEventManager(this) {
    qDebug() << "PluginTest2 loaded !!!";
    moveToThread(&mThread);
    mThread.start();
}

/**
 * @brief Initialize plugin independant application content
 * @param parent - PluginManager instance
 */
void PluginTest2::onAttach(QObject* parent) {
    Q_UNUSED(parent)

    // //////////////////////////////////////////
    // Initialize shared data here !!!
    // //////////////////////////////////////////
    set_id(8);

    // //////////////////////////////////////////
    // Add internal connections
    // //////////////////////////////////////////
    connect(&mEventManager, &EventManager::sendEvent, this, &PluginInterface::sendEvent);

    // //////////////////////////////////////////
    // Send plugins listener
    // //////////////////////////////////////////
    emit listenPlugin(mEventManager, PLUGIN1);
}

/**
 * @brief Initialize plugin application specific content
 */
void PluginTest2::onInit() {

    // TEST
    QTimer::singleShot(1000, this, [this] {
        emit sendEvent(Event(PLUGIN2_EVENT1));

        QVariant data1;
        emit getSharedData(PLUGIN1_DATA1, data1);
        qDebug() << "PLUGIN1_DATA1: " << data1;
        logV("PLUGIN1_DATA1");

        QVariant data2;
        emit getSharedData(PLUGIN1_DATA2, data2);
        qDebug() << "PLUGIN1_DATA2: " << data2;
        logW("PLUGIN1_DATA2");

        QVariant data3;
        emit getSharedData(PLUGIN1_DATA3, data3);
        qDebug() << "PLUGIN1_DATA3: " << data3;
        logI("PLUGIN1_DATA3");

        QVariant data4;
        emit getSharedData(PLUGIN1_DATA4, data4);
        qDebug() << "PLUGIN1_DATA4: " << data4;
        logE("PLUGIN1_DATA4");
    });
    // !TEST
}

/**
 * @brief Free plugin content
 */
void PluginTest2::onDetach(void) {
}
