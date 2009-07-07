QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns \
    testlib
TARGET = SettingControllerTest
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += test.cpp ../../RssCube/control/SettingController.cpp
HEADERS += test.h ../../RssCube/control/SettingController.h
