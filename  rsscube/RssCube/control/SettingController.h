#ifndef SETTINGCONTROLLER_H
#define SETTINGCONTROLLER_H

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
    ISettingObserver* mObserver;
};

#endif // SETTINGCONTROLLER_H
