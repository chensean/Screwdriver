#-------------------------------------------------
#
# Project created by QtCreator 2014-06-06T21:46:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Screwdriver
TEMPLATE = app


SOURCES += main.cpp\
    qtgui/screwdrivermainwindow.cpp \
    qtgui/qtpropertybroswer/qteditorfactory.cpp \
    qtgui/qtpropertybroswer/qtpropertybrowser.cpp \
    qtgui/qtpropertybroswer/qtpropertybrowserutils.cpp \
    qtgui/qtpropertybroswer/qtpropertymanager.cpp \
    qtgui/qtpropertybroswer/qttreepropertybrowser.cpp \
    qtgui/widgettaskmanage.cpp \
    qtgui/widgettaskcfg.cpp \
    qtgui/widgetirigframecfg.cpp \
    qtgui/widgetrtrcomcfg.cpp \
    qtgui/widgetchannelcfg.cpp \
    qtgui/irigframegraphicpreview.cpp \
    qtgui/workspacemanage.cpp \
    qtgui/newtaskdialog.cpp

HEADERS  += \
    qtgui/screwdrivermainwindow.h \
    qtgui/qtpropertybroswer/qteditorfactory.h \
    qtgui/qtpropertybroswer/qtpropertybrowser.h \
    qtgui/qtpropertybroswer/qtpropertybrowserutils_p.h \
    qtgui/qtpropertybroswer/qtpropertymanager.h \
    qtgui/qtpropertybroswer/qttreepropertybrowser.h \
    qtgui/widgettaskmanage.h \
    qtgui/widgettaskcfg.h \
    qtgui/widgetirigframecfg.h \
    qtgui/widgetrtrcomcfg.h \
    qtgui/widgetchannelcfg.h \
    qtgui/irigframegraphicpreview.h \
    qtgui/workspacemanage.h \
    qtgui/newtaskdialog.h

FORMS    += \
    qtgui/screwdrivermainwindow.ui \
    qtgui/widgettaskmanage.ui \
    qtgui/widgettaskcfg.ui \
    qtgui/widgetirigframecfg.ui \
    qtgui/widgetrtrcomcfg.ui \
    qtgui/widgetchannelcfg.ui \
    qtgui/irigframegraphicpreview.ui \
    qtgui/workspacemanage.ui \
    qtgui/newtaskdialog.ui

RESOURCES += \
    images/images.qrc
