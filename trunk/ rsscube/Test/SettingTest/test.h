#ifndef TEST_H
#define TEST_H

#include <QtTest/QtTest>

#include "../../RssCube/entity/Setting.h"

class Test : public QObject
{
    Q_OBJECT

public:
    Test();

private slots:    
    void getSettingInfo_test();
    void changeRefreshSetting_test();
    void changeDisplaySetting_test();
};

#endif // TEST_H
