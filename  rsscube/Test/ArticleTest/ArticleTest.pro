QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns \
    testlib
TARGET = ArticleTest
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += test.cpp ../../RssCube/entity/Article.cpp
HEADERS += test.h ../../RssCube/entity/Article.h
