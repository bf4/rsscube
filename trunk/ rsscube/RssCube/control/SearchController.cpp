//2009-07-07 金欢 创建框架
//2009-07-08 金欢 函数实现

#include "SearchController.h"
#include <QVector>

SearchController::SearchController()
{
}

SearchController::~SearchController()
{
}

QVector<Article> SearchController::localSearch(MatchType matchType, ReadType readType, ContentType contentType, QString keyword)
{
    return Article::localSearch(matchType,readType,contentType,keyword);
}
