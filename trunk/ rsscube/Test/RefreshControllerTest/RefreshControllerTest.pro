QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns \
    testlib
TARGET = RefreshControllerTest
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += test.cpp ../../RssCube/control/RefreshController.cpp
HEADERS += test.h ../../RssCube/control/RefreshController.h
