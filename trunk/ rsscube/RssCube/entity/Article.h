//2009-07-07 于宝 Article框架

#ifndef ARTICLE_H
#define ARTICLE_H
#include<QString>
#include<QDateTime>
#include"../other/enums.h"


class Article
{
public:
    Article();
    ~Article();
    int getId();
    QDateTime getPublishDate();
    QString getCategory();
    QString getAuthor();
    QString getTitle();
    QString getDescription();
    QString getLink();
    void writeHtml();

    QVector<Article> getArticleByChannelId(int channel);
    Article getArticle(int id);
    QVector<Article> localSearch(MatchType matchType,ReadType readType,ContentType contentType);
    int addArticle(const int id,const QDateTime &publishTime, const  QString &category,const  QString &author,
                   const  QString &title, const  QString &description, const  QString &link);

private:
    int mId;
    QDateTime mPublishDate;
    QString mCatecory;
    QString mAuthor;
    QString mTitle;
    QString mDescription;
    QString mLink;

};

#endif // ARTICLE_H
