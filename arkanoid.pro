TEMPLATE = app
TARGET = qtarkanoid
QT += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH +=  ../include src

SOURCES += \
    src/game/bricks.cpp \
    src/game/gamescene.cpp \
    src/main.cpp \
    src/menu.cpp \
    src/game/platform.cpp \
    src/rasterwindow.cpp \
    src/rectf.cpp \
    src/settingsgame.cpp

HEADERS += \
    src/game/bricks.h \
    src/game/gamescene.h \
    src/menu.h \
    src/game/platform.h \
    src/rasterwindow.h \
    src/rectf.h \
    src/settingsgame.h

FORMS += \
    src/menu.ui \
    src/settingsgame.ui

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

OBJECTS_DIR = tmp
MOC_DIR     = tmp
RCC_DIR     = tmp
UI_DIR      = tmp
