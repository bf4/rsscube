QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns \
    testlib
TARGET = SettingTest
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += test.cpp ../../RssCube/entity/Setting.cpp ../../RssCube/control/DatabaseController.cpp
HEADERS += test.h ../../RssCube/entity/Setting.h ../../RssCube/control/DatabaseController.h
