// 2009-07-07 孔乂宇 创建框架

#include "SettingController.h"

SettingController::SettingController()
{
}

SettingController::~SettingController()
{
}

void SettingController::changeRreshSetting(bool autoRefresh, float refreshInterval)
{
    Setting::changeRefreshSetting(autoRefresh,refreshInterval);
}

void SettingController::changeDisplaySetting(ReadType readType)
{
    Setting::changeDisplaySetting(readType);
    mObserver->handleDisplaySettingChanged(readType);
}

Setting SettingController::getSetting()
{
    return Setting::getSettingInfo();
}

void SettingController::setObserver(ISettingControllerObserver* observer)
{
    mObserver = observer;
}

