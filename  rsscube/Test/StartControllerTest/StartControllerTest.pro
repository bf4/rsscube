QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns \
    testlib
TARGET = StartControllerTest
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += test.cpp ../../RssCube/control/StartController.cpp
HEADERS += test.h ../../RssCube/control/StartController.h
