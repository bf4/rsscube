QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns \
    testlib
TARGET = ExitControllerTTest
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += test.cpp ../../RssCube/control/ExitController.cpp
HEADERS += test.h ../../RssCube/control/ExitController.h
