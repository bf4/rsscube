QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns \
    testlib
TARGET = ChannelDownloaderTest
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += test.cpp ../../RssCube/entity/ChannelDownloader.cpp
HEADERS += test.h ../../RssCube/entity/ChannelDownloader.h
