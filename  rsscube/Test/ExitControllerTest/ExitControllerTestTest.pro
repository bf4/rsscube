QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns \
    testlib
TARGET = ExitControllerTTest
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += test.cpp ../../RssCube/control/ExitController.cpp \
                      ../../RssCube/control/StartController.cpp \
                      ../../RssCube/entity/Setting.cpp \
                      ../../RssCube/control/DatabaseController.cpp
HEADERS += test.h ../../RssCube/control/ExitController.h \
                    ../../RssCube/control/StartController.h \
                    ../../RssCube/entity/Setting.h \
                    ../../RssCube/control/DatabaseController.h
