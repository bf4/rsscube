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
SOURCES += test.cpp ../../RssCube/control/ChannelController.cpp  ../../RssCube/control/DatabaseController.cpp \
             ../../RssCube/entity/Article.cpp  ../../RssCube/entity/Channel.cpp  ../../RssCube/entity/ChannelDownloader.cpp
HEADERS += test.h ../../RssCube/control/ChannelController.h  ../../RssCube/control/DatabaseController.h \
             ../../RssCube/entity/Article.h  ../../RssCube/entity/Channel.h  ../../RssCube/entity/ChannelDownloader.h
