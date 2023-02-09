#-------------------------------------------------
#
# Project created by QtCreator 2023-01-31T21:35:17
#
#-------------------------------------------------

QT       += core gui serialport
CONFIG   += C++11


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = upper
TEMPLATE = app


SOURCES += main.cpp\
    channelinfo.cpp \
    datashow.cpp \
        mainwindow.cpp \
    dialog_connect.cpp \
    extern_variable.cpp \
    maptrake.cpp \
    multicomtest.cpp \
    rdsscomm.cpp \
    satedist.cpp

HEADERS  += mainwindow.h \
    channelinfo.h \
    datashow.h \
    dialog_connect.h \
    extern_variable.h \
    maptrake.h \
    multicomtest.h \
    rdsscomm.h \
    satedist.h

FORMS    += mainwindow.ui \
    channelinfo.ui \
    datashow.ui \
    dialog_connect.ui \
    maptrake.ui \
    multicomtest.ui \
    rdsscomm.ui \
    satedist.ui

RESOURCES += \
    res.qrc

DISTFILES += \
    icon/save.jpg
