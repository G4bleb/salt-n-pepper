#-------------------------------------------------
#
# Project created by QtCreator 2018-05-30T14:53:58
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = salt-n-pepper
TEMPLATE = app

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
        source/main.cpp \
        source/mainwindow.cpp \
    source/mainmenu.cpp \
    source/questionsmenu.cpp \
    source/propositionsmenu.cpp

HEADERS += \
        header/mainwindow.hpp \
    header/mainmenu.hpp \
    header/questionsmenu.hpp \
    header/propositionsmenu.hpp \
    header/include.hpp

FORMS += \
        ui/mainwindow.ui \
    ui/mainmenu.ui \
    ui/questionsmenu.ui \
    ui/propositionsmenu.ui
