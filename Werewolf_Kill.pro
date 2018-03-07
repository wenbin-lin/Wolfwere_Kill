#-------------------------------------------------
#
# Project created by QtCreator 2017-04-28T11:10:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Werewolf_Kill
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    playeravatar.cpp \
    mytimer.cpp \
    character.cpp \
    gameinfo.cpp \
    Client.cpp \
    basicinfo.cpp \
    login.cpp \
    gamethread.cpp

HEADERS  += mainwindow.h \
    playeravatar.h \
    mytimer.h \
    character.h \
    gameinfo.h \
    Client.h \
    basicinfo.h \
    login.h \
    gamethread.h

FORMS    += mainwindow.ui

RESOURCES += \
    image.qrc

RC_ICONS = "werewolf_kill.ico"

DISTFILES +=
LIBS += -lwsock32
