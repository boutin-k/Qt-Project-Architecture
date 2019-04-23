#-------------------------------------------------
#
# Project created by QtCreator 2019-03-09T21:24:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtApp
TEMPLATE = app

DEPENDPATH += . ../PluginTest1 ../PluginTest2
INCLUDEPATH += ../PluginTest1 ../PluginTest2

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
    main.cpp \
    mainwindow.cpp \
    pluginmanager.cpp \
    shareddata/shareddata.cpp \
    logger/logger.cpp

HEADERS += \
    mainwindow.h \
    pluginmanager.h \
    shareddata/shareddata.h \
    logger/logger.h \
    common/plugin/plugin.h \
    common/plugin/interface.h \
    common/plugin/event/event.h \
    common/plugin/event/eventhandler.h \
    common/plugin/event/eventlist.h \
    common/plugin/event/list/eventlist_plugin1.h \
    common/plugin/event/list/eventlist_plugin2.h \
    common/macro/qswitch.h \
    common/macro/qthreadsafedecl.h \
    common/logger/defs.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
