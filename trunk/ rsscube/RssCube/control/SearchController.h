// 2009-07-07 金欢 创建框架
// 2009-07-07 金欢 添加注释

#ifndef SEARCHCONTROLLER_H
#define SEARCHCONTROLLER_H

#include <QVector>
#include "../entity/Group.h"
#include "../entity/Article.h"
#include "../other/enums.h"

class SearchController
{
public:
    ~SearchController();

    /**
      Get the instance of the controller.
      @return
      The instance of the controller.
      */
    static const SearchController & getInstance()
    {
        static SearchController instance;
        return instance;
    }

    /**
      search the articles in the local range
      @param matchType
      "MT_Whole" or "MT_Fuzzy"
      @param readType
      one of the three types:"RT_All"、" RT_Read" and "RT_Unread"
      @param contentType
      one of the four types:"CT_Author"、"CT_Title"、"CT_Url"、"CT_Summary"
      @return
      return the articles that satisfied the conditions
      */
    QVector<Article> localSearch(MatchType matchType, ReadType readType, ContentType contentType);

private:
    SearchController();
};

#endif // SEARCHCONTROLLER_H