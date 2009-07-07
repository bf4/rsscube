//2009-07-07  金欢  创建GroupController框架

#ifndef GROUPCONTROLLER_H
#define GROUPCONTROLLER_H

#include <QVector>
#include <QString>
#include "../entity/Group.h"

class GroupController
{
public:
    GroupController();
    ~GroupController();
    QVector<Group> getRootGroups();
    QVector<Group> getSubGroups(int parentId);
    int addGroup(int parentId, const QString &name);
    void remove(int id);
    void dragGroup(int groupId, int newParentId);
    void renameGroup(int id, const QString &newName);

};

#endif // GROUPCONTROLLER_H
