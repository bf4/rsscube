// 2009-07-07 孔乂宇 创建框架
// 2009-07-08 孔乂宇 实现函数

#include <QVariant>
#include <QSqlQuery>
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
    query.prepare("SELECT auto_refresh, refresh_interval, display_type FROM settings");
    query.exec();

    query.next();

    Setting setting;
    setting.mAutoRefresh = query.value(0).toBool();
    setting.mRefreshInterval = query.value(1).toDouble();
    setting.mDisplayType = (ReadType)query.value(2).toInt();

    return setting;
}

void Setting::changeRefreshSetting(bool autoRefresh ,float refreshInterval)
{
    QSqlQuery query;
    query.prepare("UPDATE settings SET auto_refresh=:auto_refresh, refresh_interval=:refresh_interval");

    query.bindValue(":auto_refresh", autoRefresh);
    query.bindValue(":refresh_interval",refreshInterval);

    query.exec();
}

void Setting::changeDisplaySetting(ReadType displayType)
{
    QSqlQuery query;
    query.prepare("UPDATE settings SET display_type=:display_type");

    query.bindValue(":display_type", displayType);

    query.exec();
}
