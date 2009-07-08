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
    return this->mId;
}

QString Article::getPublishDate()
{
    return this->mPublishDate;
}

QString Article::getCategory()
{
    return this->mCatecory;
}

QString Article::getAuthor()
{
    return this->mAuthor;
}

QString Article::getTitle()
{
    return this->mTitle;
}

QString Article::getDescription()
{
    return this->mDescription;
}

QString Article::getLink()
{
    return this->mLink;
}

bool Article::getIsRead()
{
    return this->mIsRead;
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
    QSqlQuery query;
    query.prepare("SELECT id,publish_date,category,author,title,description,link,read_type"
                   "FROM articles where id=:id");
    query.bindValue(":id",id);
    query.exec();
    Article article;
    article.mId = query.value(0).toInt();
    article.mPublishDate=query.value(1).toString();  //修改为string类型
    article.mCatecory=query.value(2).toString();
    article.mAuthor=query.value(3).toString();
    article.mTitle=query.value(4).toString();
    article.mDescription=query.value(5).toString();
    article.mLink=query.value(6).toString();
    article.mIsRead=query.value(7).toBool();

    return article;
}

QVector<Article> Article::localSearch(MatchType matchType,ReadType readType,ContentType contentType,QString keyword)
{
    QSqlQuery query;
    QVector<Article> ret;
    Article article;
    QString searchWord="";
    if(matchType == MT_Whole)
    {
        searchWord=keyword;
    }
    else searchWord="%"+keyword+"%";
    QString conType=convertContentType(contentType);
    if(readType==RT_All)
    {
        query.prepare("SELECT id,publish_date,category,author,title,description,link,read_type"
                   "FROM articles where :contentType like :keyword");
        query.bindValue(":contentType",conType);
        query.bindValue(":keyword",searchWord);
        query.exec();
    }
    else
    {
        QString reType;
        if(readType==RT_Read)
            reType="true";
        else reType="false";

        query.prepare("SELECT id,publish_date,category,author,title,description,link,read_type"
                       "FROM articles where read_type=:readType and :contentType like :keyword");
        query.bindValue(":readType",reType);
        query.bindValue(":contentType",conType);
        query.bindValue(":keyword",searchWord);

        query.exec();
    }
    while(query.next())
    {
        article.mId = query.value(0).toInt();
        article.mPublishDate=query.value(1).toString();
        article.mCatecory=query.value(2).toString();
        article.mAuthor=query.value(3).toString();
        article.mTitle=query.value(4).toString();
        article.mDescription=query.value(5).toString();
        article.mLink=query.value(6).toString();
        article.mIsRead=query.value(7).toBool();

        ret.push_back(article);
    }
    return ret;
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

QString Article::convertContentType(ContentType contentType)
{
    QString type;
    switch (contentType)
    {
            case CT_Author:    type="author";
                break;
            case CT_Title:       type="title";
                break;
            case CT_Url:        type="url";
                break;
            case CT_Summary:  type="description";
                break;
    }
    return  type;
}
