#ifndef TEST_H
#define TEST_H

#include <QtTest/QtTest>

#include "../../RssCube/control/StartController.h"
#include "../../RssCube/entity/Setting.h"

class Test : public QObject
{
    Q_OBJECT
public:
    Test();

private slots:
    void changeRefreshSettingBeforeStart_test();
    void changeRefreshSettingAfterStart_test();
};

#endif // TEST_H
