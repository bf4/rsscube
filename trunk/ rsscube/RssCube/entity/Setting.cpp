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
    return mAutoRefresh;
}

float Setting::getRefreshInterval()
{
    return mRefreshInterval;
}

ReadType Setting::getDisplayType()
{
    return mDisplayType;
}

Setting Setting::getSettingInfo()
{
    QSqlQuery query;
    query.prepra("SELECT auto_refresh, refresh_interval, display_type"
                  "FROM settings");
    query.exec();

    query.next();

    Setting setting;
    setting.mAutoRefresh=query.value(0).toBool();
    setting.mRefreshInterval=query.value(1).toFloat();
    setting.mDisplayType=query.value(2).toInt();

    return setting;
}

void Setting::changeRefreshSetting(bool autoRefresh ,float refreshInterval)
{
    QSqlQuery query;
    query.prepare("UPDATE groups SET auto_refresh=:auto_refresh, refresh_intervarl=:refresh_interval");

    query.bindValue(":auto_refresh", autoRefresh);
    query.bindValue(":refresh_interval",refreshInterval);

    query.exec();
}

void Setting::changeDisplaySetting(ReadType readType)
{
    QSqlQuery query;
    query.prepare("UPDATE groups SET display_type=:display_type");

    query.bindValue(":display_type", displayType);

    query.exec();
}
