// 2009-07-07 裴小星 创建框架

#ifndef ENUM_H
#define ENUM_H

enum DownloadState
{
    Success,
    Timeout,
    RssFormatError
};

enum MatchType
{
    Whole,
    Fuzzy
};

enum ReadType
{
    All,
    Read,
    Unread
};

enum ContentType
{
    Author,
    Title,
    Url,
    Summary
};

#endif // ENUM_H
