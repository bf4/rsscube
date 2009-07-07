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

void Setting::changeDispalySetting(ReadType readType)
{
}
