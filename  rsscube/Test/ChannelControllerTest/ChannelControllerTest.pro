QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns \
    testlib
TARGET = ChannelControllerTest
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += test.cpp ../../RssCube/control/ChannelController.cpp
HEADERS += test.h ../../RssCube/control/ChannelController.h
