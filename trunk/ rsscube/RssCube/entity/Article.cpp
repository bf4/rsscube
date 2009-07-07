//2009-07-07 于宝 Article框架

#include "Article.h"
#include"../other/enums.h"
#include<QVector>

Article::Article()
{

}
Article::~Article()
{

}
int Article::getId()
{

}
QDateTime Article::getPublishDate()
{

}
QString Article::getCategory()
{

}
QString Article::getAuthor()
{

}
QString Article::getTitle()
{

}
QString Article::getDescription()
{

}
QString Article::getLink()
{

}
void Article::writeHtml()
{

}
QVector<Article> Article::getArticleByChannelId(int channel)
{

}

Article Article::getArticle(int id)
{

}
QVector<Article> Article::localSearch(MatchType matchType,ReadType readType,ContentType contentType)
{

}

int Article::addArticle(const int id,const QDateTime &publishTime, const  QString &category,const  QString &author,
                   const  QString &title, const  QString &description, const  QString &link)
{

}












