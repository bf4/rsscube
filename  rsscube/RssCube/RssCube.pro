QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns \
    testlib
TARGET = RssCube
TEMPLATE = app
SOURCES += main.cpp
HEADERS += 
FORMS += 
include(boundary/boundary.pri)
include(control/control.pri)
include(entity/entity.pri)
include(other/other.pri)
include(resource/resource.pri)
OTHER_FILES += rss_cube.db
