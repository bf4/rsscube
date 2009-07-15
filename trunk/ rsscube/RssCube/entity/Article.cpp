// 2009-07-07 于宝 创建框架
// 2009-07-08 于宝 实现函数
// 2009－07－08 于宝 修改publishDate类型为QString

#include <QMessageBox>

#include <QSqlQuery>
#include <QVariant>
#include "Article.h"

Article::Article()
{
}

Article::~Article()
{
}

int Article::getId() const
{
    return this->mId;
}

QString Article::getPublishDate() const
{
    return this->mPublishDate;
}

QString Article::getCategory() const
{
    return this->mCatecory;
}

QString Article::getAuthor() const
{
    return this->mAuthor;
}

QString Article::getTitle() const
{
    return this->mTitle;
}

QString Article::getDescription() const
{
    return this->mDescription;
}

QString Article::getLink() const
{
    return this->mLink;
}

bool Article::getIsRead() const
{
    return this->mIsRead;
}

QString Article::getHtml(int articleId)
{
    // ＜head＞
  //＜meta http-equiv="content-Type" content="text/html; charset=gb2312"＞
  //＜/head＞
    Article article=getArticle(articleId);
    QString ret="";
    ret=ret+"<HTML>"+"<H1>"+article.getTitle()+"</H1>"+"\n";
    ret=ret+"<HEAD>"+"<META http-equiv=\"content-Type\" content=\"text/html; charset=utf-8\">"+"</HEAD>";
    ret=ret+"<P>"+"Publish Time: "+article.getPublishDate()+"<Br>";
    ret=ret+"Author: "+article.getAuthor()+"<Br>";
    ret=ret+"Category: "+article.getCategory()+"<Br>";
    ret=ret+"</P>";
    ret=ret+"<P>"+"Summary: "+article.getDescription()+"</P>";
    ret=ret+"<P>"+"<A href='"+article.getLink()+"'>"+"More..."+"</A>"+"</P>";
    ret=ret+"<HTML>";
    return ret;
}

QVector<Article> Article::getArticlesByChannelId(int channelId)
{
    QVector<Article> ret;
    QSqlQuery query;
    query.prepare("SELECT id,publish_date,category,author,title,description,link,read_type "
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
        article.mIsRead = query.value(7).toBool();
        ret.push_back(article);
    }

    return ret;
}

Article Article::getArticle(int id)
{
    QSqlQuery query;
    Article article;
    query.prepare("SELECT id,publish_date,category,author,title,description,link,read_type "
                   "FROM articles where id=:id");
    query.bindValue(":id",id);
    query.exec();
    if(query.next())
    {
        article.mId = query.value(0).toInt();
        article.mPublishDate=query.value(1).toString();  //修改为string类型
        article.mCatecory=query.value(2).toString();
        article.mAuthor=query.value(3).toString();
        article.mTitle=query.value(4).toString();
        article.mDescription=query.value(5).toString();
        article.mLink=query.value(6).toString();
        article.mIsRead=query.value(7).toBool();
    }
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
        query.prepare("SELECT id,publish_date,category,author,title,description,link,read_type "
                   "FROM articles where " + conType + " like :keyword");
        query.bindValue(":keyword",searchWord);
        query.exec();
    }
    else
    {
        //QString reType;
        //if(readType==RT_Read)
            //reType="True";
        //else reType="False";

        query.prepare("SELECT id,publish_date,category,author,title,description,link,read_type "
                      "FROM articles where (read_type='false' or read_type='False') and "
                      + conType + " like :keyword ");
        //query.bindValue(":readType", reType);
        query.bindValue(":keyword", searchWord);

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

    query.prepare("INSERT INTO articles(channel_id,publish_date,category, author,title,description,link) "
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
    QSqlQuery query;
    query.prepare("delete from articles where channel_id=:channelId");
    query.bindValue(":channelId",channelId);
    query.exec();
}

void Article::logicRemove(int channelId)
{
    QSqlQuery query;
    query.prepare("UPDATE articles SET channel_id = :removedId where channel_id=:channelId");
    query.bindValue(":removedId", -channelId);
    query.bindValue(":channelId", channelId);
    query.exec();
}

void Article::logicRecover(int channelId)
{
    QSqlQuery query;
    query.prepare("UPDATE articles SET channel_id = :channelId where channel_id=:removedId");
    query.bindValue(":removedId", -channelId);
    query.bindValue(":channelId", channelId);
    query.exec();
}

void Article::clearArticles()
{
    QSqlQuery query;
    query.exec("DELETE FROM articles WHERE channel_id < 0");
}

void Article::setRead(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE articles "
                  "SET read_type='True' "
                  "WHERE id=:id ");
    query.bindValue(":id", id);
    query.exec();
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
            case CT_Url:        type="link";
                break;
            case CT_Summary:  type="description";
                break;
    }
    return  type;
}
