#-------------------------------------------------
#
# Project created by QtCreator 2015-04-10T13:56:41
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Star_Stuff
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    maingame.cpp \
    settings.cpp \
    setroute.cpp

HEADERS  += mainwindow.h \
    maingame.h \
    settings.h \
    setroute.h

FORMS    += mainwindow.ui \
    maingame.ui \
    settings.ui \
    setroute.ui

RESOURCES += \
    res.qrc
