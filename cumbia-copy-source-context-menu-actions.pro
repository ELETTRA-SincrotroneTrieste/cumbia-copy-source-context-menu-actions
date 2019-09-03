#-------------------------------------------------
#
# Project created by QtCreator 2019-09-03T15:28:56
#
#-------------------------------------------------

include(/usr/local/cumbia-libs/include/cumbia-qtcontrols/cumbia-qtcontrols.pri)

QT       += core gui

TARGET = cumbia-copy-source-context-menu-actions
TEMPLATE = lib
CONFIG += plugin

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        cumbia-copy-source-ctx-menu-action.cpp

HEADERS += \
        cumbia-copy-source-ctx-menu-action.h
DISTFILES += cumbia-copy-source-context-menu-actions.json  \
    README.md

unix {
    target.path = $${DEFINES_CUMBIA_QTCONTROLS_PLUGIN_DIR}
    INSTALLS += target
}
