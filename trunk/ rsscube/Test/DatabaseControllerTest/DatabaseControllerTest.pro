QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns \
    testlib
TARGET = DatabaseControllerTest
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += test.cpp ../../RssCube/control/DatabaseController.cpp
HEADERS += test.h ../../RssCube/control/DatabaseController.h
