QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    main.cpp \
	platform.cpp \
	pooltablescene.cpp \
	rasterwindow.cpp \
	rectf.cpp \


HEADERS += \
    platform.h \
    pooltablescene.h \
    rasterwindow.h \
    rectf.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
