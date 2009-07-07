// 2009-07-07 于宝 创建框架
// 2009-07-07 于宝 添加注释

#ifndef ARTICLE_H
#define ARTICLE_H

#include <QString>
#include <QDateTime>
#include "../other/enums.h"

class Article
{
public:
    Article();
    ~Article();
    /**
       get the article's id
       @return
       the article's id
     */
    int getId();

    /**
       get the article's publish time
       @return
       the article's publish time
     */
    QDateTime getPublishDate();

    /**
       get the article's
       @return
       the article's category
     */
    QString getCategory();

    /**
       get the article's author
       @return
       the article's author
     */
    QString getAuthor();

    /**
       get the article's title
       @return
       the article's title
     */
    QString getTitle();

    /**
       get the article's description
       @return
       the article's description
     */
    QString getDescription();

    /**
       get the article's link address
       @return
       the article's link address
     */
    QString getLink();

    /**
     display the article's address on the address line of the browser
     */
    void writeHtml();

    /**
      get the article by the article's id
      @param channel
      the channel's id
      @return QVector<Article>
      the articles collection
      */
    QVector<Article> getArticleByChannelId(int channelId);

    /**
       get the article by the id
       @param id
       the article's id
       @return Article
       the article
     */
    Article getArticle(int id);

    /**
       search the article according to the three params
       @param matchType
       Fuzzy or complete same
       @param readType
       all or readed or unread
       @return  QVector<Article>
       the results that equal to the request
     */
    QVector<Article> localSearch(MatchType matchType,ReadType readType,ContentType contentType);

     /**
      add a new article
      @param
      the article's attributes including channelId, publish time, category, author, title,description and link
      @return
      the new article's id
      */
    int addArticle(const int channelId,const QDateTime &publishTime, const  QString &category,const  QString &author,
                   const  QString &title, const  QString &description, const  QString &link);

private:
    /** the article's id  */
    int mId;

    /** the article's publish time  */
    QDateTime mPublishDate;

    /** the article's  category */
    QString mCatecory;

    /** the article's  author */
    QString mAuthor;

    /** the article's title  */
    QString mTitle;

    /** the article's description  */
    QString mDescription;

    /** the article's link  */
    QString mLink;

};

#endif // ARTICLE_H
