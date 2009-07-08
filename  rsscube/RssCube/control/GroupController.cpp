// 2009-07-07  金欢  创建框架
// 2009-07-08  金欢  函数实现

#include <QVector>
#include <QVariant>
#include <QSqlQuery>
#include "GroupController.h"

GroupController::GroupController()
{
}

GroupController::~GroupController()
{
}

QVector<Group> GroupController::getSubGroups(int parentId)
{
    return Group::getSubGroups(parentId);
}

int GroupController::addGroup(int parentId, const QString &name)
{
    return Group::addGroup(parentId, name);
}

void GroupController::remove(int id)
{
    return Group::removeGroup(id);
}

void GroupController::dragGroup(int groupId, int newParentId)
{
   return Group::setParent(groupId,newParentId);
}

void GroupController::renameGroup(int id, const QString &newName)
{
    return Group::renameGroup(id,newName);
}


