#ifndef SETTING_H
#define SETTING_H

// 2009-07-07 孔乂宇 创建框架
// 2009-07-07 孔乂宇 添加注释

#include "../other/enums.h"

class Setting
{
public:
    Setting();

    ~Setting();

    /**
       get whether autorefresh or not
       @return
       autorefresh information
       */
    bool getAutoRefresh();

     /**
      get the refresh interval
      @return
      refresh interval information
      */
    float getRefreshInterval();

     /**
      get the display type
      @return
      display type information
      */
    ReadType getDisplayType();

     /**
      get the setting information
      @return
      setting information
      */
    static Setting getSettingInfo();

     /**
      change the refresh setting
      @param autoRefrsh refrshInterval
      new refresh setting
      */
    static void changeRefreshSetting(bool autoRefresh ,float refreshInterval);

     /**
      change the display setting
      @param redType
      new display setting
      */
    static void changeDisplaySetting(ReadType readType);

private:
    /** use to save autorefresh information */
    bool mAutoRefresh;

    /** use to save refrshinterval information */
    float mRefreshInterval;

    /** use to save displaytype information */
    ReadType mDisplayType;
};

#endif // SETTING_H
