// 2009-07-07 吴双 创建框架

#include "Group.h"

Group::Group()
{
}

Group::~Group()
{
}

int Group::getId()
{
}

QString Group::getName()
{
}

QVector<Group> Group::getRootGroups()
{
}

QVector<Group> Group::getSubGroups(int id)
{
}

int Group::addGroup(int parentId, const QString &name)
{
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
