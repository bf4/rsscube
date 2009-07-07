//2009-07-07 金欢 创建SearchController框架

#ifndef SEARCHCONTROLLER_H
#define SEARCHCONTROLLER_H

#include <QVector>
#include "../entity/Group.h"
#include "../entity/Article.h"

class SearchController
{
public:
    SearchController();
    ~SearchController();
    QVector<Article> localSearch(MatchType matchType, ReadType readType, ContentType contentType);
};

#endif // SEARCHCONTROLLER_H
