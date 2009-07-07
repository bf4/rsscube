QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns \
    testlib
TARGET = RecommendControllerTest
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += test.cpp ../../RssCube/control/RecommendController.cpp
HEADERS += test.h ../../RssCube/control/RecommendController.h
