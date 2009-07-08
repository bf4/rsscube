// 2009-07-07 吴双 创建框架

#include <QSqlQuery>
#include <QVariant>
#include "Group.h"

Group::Group()
{
}

Group::~Group()
{
}

int Group::getId()
{
    return mId;
}

QString Group::getName()
{
    return mName;
}

QVector<Group> Group::getRootGroups()
{
    QVector<Group> tmp;
    QSqlQuery query;
    query.prepare("SELECT id, name"
                   "FROM groups"
                   "WHERE parent_id = 0");

    query.exec();

    while(query.next())
    {
        Group group;
        group.mId = query.value(0).toInt();
        group.mName=query.value(1).toString();
        tmp.push_back(group);
    }
}

QVector<Group> Group::getSubGroups(int id)
{
    QVector<Group> tmp;
    QSqlQuery query;
    query.prepare("SELECT id, name"
                   "FROM groups"
                   "WHERE parent_id = :id");

    query.exec();

    while(query.next())
    {
        Group group;
        group.mId = query.value(0).toInt();
        group.mName=query.value(1).toString();
        tmp.push_back(group);
    }
}

int Group::addGroup(int parentId, const QString &name)
{
    QSqlQuery query;
    query.prepare("INSERT INTO groups(parent_id,name) "
                  "VALUES(:parentId,:name) ");

    query.bindValue(":parentId", parentId);
    query.bindValue(":name", name);

    query.exec();
    return query.lastInsertId().toInt();
}

void Group::removeGroup(int id)
{
}

void Group::renameGroup(int id, const QString &name)
{
}

void Group::setParent(int id, int parentId)
{
}
