// 2009-07-07  金欢  创建框架
// 2009-07-07  金欢  添加注释
// 2009-07-08  裴小星 测试通过

#ifndef GROUPCONTROLLER_H
#define GROUPCONTROLLER_H

#include <QVector>
#include <QString>
#include "../entity/Channel.h"
#include "../entity/Group.h"

class GroupController
{
public:
    ~GroupController();

    /**
      Get the instance of the controller.
      @return
      The instance of the controller.
      */
    static GroupController & getInstance()
    {
        static GroupController instance;
        return instance;
    }

    /**
      Get the groups included in the specific group.
      @param parentId
      The id of the specific group.
      @return
      The groups included in the specific group.
      */
    QVector<Group> getSubGroups(int parentId);

    /**
      Get the channel included in the specific group.
      @param groupId
      The id of the specific group.
      @return
      The groups included in the specific group.
      */
    QVector<Channel> getSubChannels(int groupId);

    /**
      Add a new group
      @param parentId
      The id of the group which is going to be the new group's parent.
      (If the group is added to the root, the parentId will be 0.)
      @param name
      The name of the new group.
      @return
      The new group's id.
      */
    int addGroup(int parentId, const QString &name);

    /**
      Remove the group of the specific group.
      @param groupId
      The id of the group which is going to be removed.
      */
    void removeGroup(int groupId);

    /**
      Drag the specific group to a new parent group.
      @param groupId
      The id of chosen group
      @param newParentId
      The id of the new paren of the specific group.
      */
    void dragGroup(int groupId, int newParentId);

    /**
      Rename a specific group.
      @param id
      The id of the specific group.
      @param newName
      The new name of the specific group.
      */
    void renameGroup(int id, const QString &newName);

private:
    GroupController();
};

#endif // GROUPCONTROLLER_H
