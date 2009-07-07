QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns \
    testlib
TARGET = GroupControllerTest
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += test.cpp ../../RssCube/control/GroupController.cpp
HEADERS += test.h ../../RssCube/control/GroupController.h
