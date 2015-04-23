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
    setroute.cpp \
    location.cpp \
    location_pushbutton.cpp

HEADERS  += mainwindow.h \
    maingame.h \
    settings.h \
    setroute.h \
    location.h \
    location_pushbutton.h

FORMS    += mainwindow.ui \
    maingame.ui \
    settings.ui \
    setroute.ui

RESOURCES += \
    res.qrc

#-------------------------------
# TODO: uncomment when ready to release to add icon. Leave commented to reduce compile times.
#
# win32:RC_ICONS += ssicon.ico
#-------------------------------
