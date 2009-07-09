#ifndef TEST_H
#define TEST_H

#include <QtTest/QtTest>

#include "../../RssCube/entity/Group.h"

class Test : public QObject
{
    Q_OBJECT

public:
    Test();

private slots:
    void getSubGroups_test();
    void addGroup_test();
    void removeGroup_test();
    void renameGroup_test();
    void setParent_test();
};

#endif // TEST_H
