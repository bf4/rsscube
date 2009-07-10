// 2009-07-07 孔乂宇 创建框架
// 2009-07-09 孔乂宇 实现函数

#include "SettingController.h"
#include "RefreshController.h"

SettingController::SettingController()
{
}

SettingController::~SettingController()
{
}

void SettingController::changeRreshSetting(bool autoRefresh, float refreshInterval)
{
    Setting::changeRefreshSetting(autoRefresh,refreshInterval);
    RefreshController::getInstance().updateRefreshSeting();
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

