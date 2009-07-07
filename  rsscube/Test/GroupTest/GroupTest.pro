QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns \
    testlib
TARGET = GroupTest
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += test.cpp ../../RssCube/entity/Group.cpp
HEADERS += test.h ../../RssCube/entity/Group.h
