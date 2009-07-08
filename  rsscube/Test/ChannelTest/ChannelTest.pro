QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns \
    testlib
TARGET = ChannelTest
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += test.cpp ../../RssCube/entity/Channel.cpp ../../RssCube/control/DatabaseController.cpp
HEADERS += test.h ../../RssCube/entity/Channel.h ../../RssCube/control/DatabaseController.h
