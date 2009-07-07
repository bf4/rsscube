//2009-07-07  金欢  创建GroupController框架

#include "GroupController.h"
#include <QVector>

GroupController::GroupController()
{
}

GroupController::~GroupController()
{
}

QVector<Group> GroupController::getRootGroups()
{
}

QVector<Group> GroupController::getSubGroups(int parentId)
{
}

int GroupController::addGroup(int parentId, const QString &name)
{
}

void GroupController::remove(int id)
{
}

void GroupController::dragGroup(int groupId, int newParentId)
{
}

void GroupController::renameGroup(int id, const QString &newName)
{
}


