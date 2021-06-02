QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
	bricks.cpp \
	gamescene.cpp \
    main.cpp \
	menu.cpp \
	platform.cpp \
	rasterwindow.cpp \
	rectf.cpp \
    settingsgame.cpp


HEADERS += \
	bricks.h \
	gamescene.h \
	menu.h \
    platform.h \
    rasterwindow.h \
    rectf.h \
    settingsgame.h

FORMS += \
    mainwindow.ui \
    menu.ui \
    settingsgame.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
