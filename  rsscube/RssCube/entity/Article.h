// 2009-07-07 于宝 创建框架
// 2009-07-07 于宝 添加注释
//2009－07－08 于宝 修改publishDate类型为QString
//2009－07－08 于宝  添加Article::removeArticles函数, writeHtml()改为getHtml()
//下午添加 isRead,getIsRead()  修改localSearch（），添加关键字，channelController待更改,
//添加函数convertContentType() ,getHtml(int articleId)


#ifndef ARTICLE_H
#define ARTICLE_H

#include <QString>
#include <QVector>
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
    QString getPublishDate();

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
       get the article's read type
       @return
       the article's read state
     */
    bool getIsRead();

    /**
     display the article's address on the address line of the browser
     */
    static QString getHtml(int articleId);

    /**
      get the article by the article's id
      @param channel
      the channel's id
      @return QVector<Article>
      the articles collection
      */
    static QVector<Article> getArticlesByChannelId(int channelId);

    /**
       get the article by the id
       @param id
       the article's id
       @return Article
       the article
     */
    static Article getArticle(int id);

    /**
       search the article according to the three params
       @param matchType
       Fuzzy or complete same
       @param readType
       all or readed or unread
       @return  QVector<Article>
       the results that equal to the request
     */
    static QVector<Article> localSearch(MatchType matchType,ReadType readType,ContentType contentType,QString keyword);

     /**
      add a new article
      @param
      the article's attributes including channelId, publish time, category, author, title,description and link
      @return
      the new article's id
      */
    static int addArticle(const int channelId,const QString &publishTime, const  QString &category,const  QString &author,
                   const  QString &title, const  QString &description, const  QString &link);

     /**
      remove all articles in the specific channel
      @param
      the id of the channel whose articles are to be removed
      */
    static void removeArticles(int channelId);

private:
     /**
      convert the emun type to string
      @param
      ContetType
      @return
      QString
      */
   static QString convertContentType(ContentType contentType);
private:
    /** the article's id  */
    int mId;

    /** the article's publish time  */
    QString mPublishDate;

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
    /** is the article readed?*/
    bool mIsRead;

};

#endif // ARTICLE_H
