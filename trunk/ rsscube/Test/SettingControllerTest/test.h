#ifndef TEST_H
#define TEST_H

#include <QtTest/QtTest>

#include "../../RssCube/control/SettingController.h"

class Test : public QObject, ISettingControllerObserver
{
    Q_OBJECT

public:
    Test();
    void handleDisplaySettingChanged(ReadType readType);

private slots:
    void changeRreshSetting_test();
    void changeDisplaySetting_test();
};

#endif // TEST_H
