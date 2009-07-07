// 2009-07-07 孔乂宇 创建框架

#ifndef SETTINGCONTROLLER_H
#define SETTINGCONTROLLER_H

#include "../other/enums.h"
#include "../other/interfaces.h"
#include "../entity/Setting.h"

class SettingController
{
public:
    SettingController();

    ~SettingController();

    void changeRreshSetting(bool autoRefresh,float refreshInterval);

    void changeDisplaySetting(ReadType readType);

    Setting getSetting();

    void setObserver(ISettingControllerObserver* observer);

 private:
    ISettingControllerObserver* mObserver;
};

#endif // SETTINGCONTROLLER_H
