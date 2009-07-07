QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns \
    testlib
TARGET = SearchControllerTest
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += test.cpp ../../RssCube/control/SearchController.cpp
HEADERS += test.h ../../RssCube/control/SearchController.h
