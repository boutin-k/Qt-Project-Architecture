#-------------------------------------------------
#
# Project created by QtCreator 2019-03-10T22:12:55
#
#-------------------------------------------------

QT       -= gui

TARGET = PluginTest1
TEMPLATE = lib
DESTDIR  = ../Reload/plugins

CONFIG  += plugin
DEFINES += PLUGINTEST1_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    plugintest1.cpp \
    eventmanager.cpp

HEADERS += \
    plugintest1.h \
    eventmanager.h \
    common/plugin/plugin.h \
    common/plugin/interface.h \
    common/plugin/event/event.h \
    common/plugin/event/eventhandler.h \
    common/plugin/event/eventlist.h \
    common/plugin/event/list/eventlist_plugin1.h \
    common/plugin/event/list/eventlist_plugin2.h \
    common/logger/defs.h \
    common/macro/qswitch.h \
    common/macro/qthreadsafedecl.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
