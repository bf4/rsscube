#ifndef SETTING_H
#define SETTING_H

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
