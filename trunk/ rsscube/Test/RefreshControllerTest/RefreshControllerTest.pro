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
SOURCES += test.cpp \
              ../../RssCube/control/RefreshController.cpp \
              ../../RssCube/entity/Setting.cpp \
              ../../RssCube/entity/Channel.cpp \
              ../../RssCube/entity/ChannelDownloader.cpp \
              ../../RssCube/entity/Article.cpp
HEADERS += test.h \
              ../../RssCube/entity/Setting.cpp \
              ../../RssCube/control/RefreshController.h\
               ../../RssCube/entity/Channel.cpp \
              ../../RssCube/entity/ChannelDownloader.cpp \
              ../../RssCube/entity/Article.cpp
