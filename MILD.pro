#-------------------------------------------------
#
# Project created by QtCreator 2017-08-08T17:26:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MILD
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
CONFIG += c++14

SOURCES += \
    about.cpp \
    DataEntries.cpp \
    entryitem.cpp \
    examplebox.cpp \
    main.cpp \
    settings.cpp \
    window.cpp

HEADERS += \
    about.hpp \
    DataEntries.hpp \
    entryitem.hpp \
    examplebox.hpp \
    Functions.hpp \
    resource.h \
    settings.hpp \
    StandardEntries.hpp \
    ui_about.h \
    ui_examplebox.h \
    ui_settings.h \
    ui_window.h \
    window.h

DISTFILES += \
    Resources/lucidity.png \
    Resources/lucidity icon.ico \
    Resources/OpenFolder icon.ico \
    Resources/Question icon.ico \
    Resources/Quit icon.ico \
    Resources/Refresh icon.ico \
    Resources/Settings icon.ico \
    MILD.pro.user \
    MILD.rc \
    MILD.pro.user \
    MILD.pro.autosave

FORMS += \
    about.ui \
    examplebox.ui \
    settings.ui \
    window.ui

RESOURCES += \
    window.qrc
