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

QVector<Group> Group::getSubGroups(int id)
{
    QVector<Group> tmp;
    QSqlQuery query;
    query.prepare("SELECT id, name "
                   "FROM groups "
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
    query.prepare("INSERT INTO groups(parent_id,name)  "
                  "VALUES(:parentId,:name) ");

    query.bindValue(":parentId", parentId);
    query.bindValue(":name", name);

    query.exec();
    return query.lastInsertId().toInt();
}

void Group::removeGroup(int id)
{
    QSqlQuery query;

    query.prepare("DELETE * FROM groups "
                  "WHERE id=:id");

    query.bindValue(":id",id);

    query.exec();
}

void Group::renameGroup(int id, const QString &name)
{
    QSqlQuery query;

    query.prepare("UPDATE groups "
                   "SET name = :name "
                   "WHERE id = :id");

    query.bindValue(":id",id);
    query.bindValue(":name",id);

    query.exec();
}

void Group::setParent(int id, int parentId)
{
    QSqlQuery query;

    query.prepare("UPDATE channels "
                  "SET parent_id=:parentId "
                  "WHERE id=:id ");

    query.bindValue(":parentId",parentId);
    query.bindValue(":id",id);

    query.exec();
}
