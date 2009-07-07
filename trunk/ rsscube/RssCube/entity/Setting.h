#ifndef SETTING_H
#define SETTING_H

// 2009-07-07 孔乂宇 创建框架

#include "../other/enums.h"

class Setting
{
public:
    Setting();

    ~Setting();

    bool getAutoRefresh();

    float getRefreshInterval();

    ReadType getDisplayType();

    Setting getSettingInfo();

    void changeRefreshSetting(bool autoRefresh ,float refreshInterval);

    void changeDispalySetting(ReadType readType);

private:
    bool mAutoRefresh;
    float mRefreshInterval;
    ReadType mDisplayType;
};

#endif // SETTING_H
