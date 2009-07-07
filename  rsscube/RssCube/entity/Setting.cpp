// 2009-07-07 孔乂宇 创建框架

#include "Setting.h"

Setting::Setting()
{
}

Setting::~Setting()
{
}

bool Setting::getAutoRefresh()
{
}

float Setting::getRefreshInterval()
{
}

ReadType Setting::getDisplayType()
{
}

Setting Setting::getSettingInfo()
{
    return Setting();
}

void Setting::changeRefreshSetting(bool autoRefresh ,float refreshInterval)
{
}

void Setting::changeDisplaySetting(ReadType readType)
{
}
