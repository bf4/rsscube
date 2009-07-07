// 2009-07-07 裴小星 创建框架

#ifndef ENUM_H
#define ENUM_H

enum DownloadState
{
    DS_Success,
    DS_Timeout,
    DS_RssFormatError
};

enum MatchType
{
    MT_Whole,
    MT_Fuzzy
};

enum ReadType
{
    RT_All,
    RT_Read,
    RT_Unread
};

enum ContentType
{
    CT_Author,
    CT_Title,
    CT_Url,
    CT_Summary
};

#endif // ENUM_H
