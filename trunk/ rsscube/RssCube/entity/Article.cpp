// 2009-07-07 于宝 创建框架
//2009－07－08 于宝 修改publishDate类型为QString

#include <QSqlQuery>
#include <QVariant>
#include "Article.h"

Article::Article()
{
}

Article::~Article()
{
}

int Article::getId()
{
}

QString Article::getPublishDate()
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

void Article::getHtml()
{
}

QVector<Article> Article::getArticlesByChannelId(int channelId)
{
    QVector<Article> ret;
    QSqlQuery query;
    query.prepare("SELECT id,publish_date,category,author,title,description,link"
                   "FROM articles where channel_id=:channelId");

    query.bindValue(":channelId",channelId);
    query.exec();

    while(query.next())
    {
        Article article;
        article.mId = query.value(0).toInt();
        article.mPublishDate=query.value(1).toString();  //修改为string类型
        article.mCatecory=query.value(2).toString();
        article.mAuthor=query.value(3).toString();
        article.mTitle=query.value(4).toString();
        article.mDescription=query.value(5).toString();
        article.mLink=query.value(6).toString();
        ret.push_back(article);
    }

    return ret;
}

Article Article::getArticle(int id)
{
}

QVector<Article> Article::localSearch(MatchType matchType,ReadType readType,ContentType contentType)
{
}

int Article::addArticle(const int channelId,const QString &publishTime, const  QString &category,const  QString &author,
                   const  QString &title, const  QString &description, const  QString &link)
{
    QSqlQuery query;
    query.prepare("INSERT INTO articles(channel_id,publishTime,category, author,title,description,link) "
                  "VALUES(:channelId,:publishTime,:category,:author,:title,:description,:link) ");

    query.bindValue(":channelId", channelId);
    query.bindValue(":publishTime", publishTime);
    query.bindValue(":category", category);
    query.bindValue(":author", author);
    query.bindValue(":title", title);
    query.bindValue(":description", description);
    query.bindValue(":link", link);

    query.exec();
    return query.lastInsertId().toInt();
}

void Article::removeArticles(int channelId)
{
}