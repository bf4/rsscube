// 2009-07-07 孔乂宇 创建框架
// 2009-07-07 孔乂宇 添加注释

#ifndef SETTINGCONTROLLER_H
#define SETTINGCONTROLLER_H

#include "../other/enums.h"
#include "../other/interfaces.h"
#include "../entity/Setting.h"

class SettingController
{
public:
    ~SettingController();

    /**
      Get the instance of the controller.
      @return
      The instance of the controller.
      */
    static SettingController & getInstance()
    {
        static SettingController instance;
        return instance;
    }

    /**
      change the refresh setting information
      @param autoRefresh refreshInterval
      new refresh setting
      */
    void changeRreshSetting(bool autoRefresh,float refreshInterval);

    /**
      change the display setting information
      @param readType
      new display setting
      */
    void changeDisplaySetting(ReadType readType);

    /**
      get the setting information
      @return Setting
      */
    Setting getSetting();

    /**
      Set the observer. When the display setting is channged, the setting will notify the observer.
      @param *observer
      The observer to notify.
      */
    void setObserver(ISettingControllerObserver* observer);

 private:
    SettingController();

    /**  When the display setting is channged, the observer will be notified. */
    ISettingControllerObserver* mObserver;
};

#endif // SETTINGCONTROLLER_H
