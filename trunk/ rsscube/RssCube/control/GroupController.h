// 2009-07-07  金欢  创建框架
// 2009-07-07  金欢  添加注释

#ifndef GROUPCONTROLLER_H
#define GROUPCONTROLLER_H

#include <QVector>
#include <QString>
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
      get the children's groups of the chose group
      @param parentId
      the chosen group's id
      @return
      get the children's groups of the chose group
      */
    QVector<Group> getSubGroups(int parentId);

    /**
      add a new group
      @param parentId
      the id of the group which is going to be the new group's parent
      @param name
      the name of the new group
      @return
      return the new group's id
      */
    int addGroup(int parentId, const QString &name);

    /**
      delete the group of the chosen group, including all the children it has
      @param id
      the id of the channel which is going to be deleted
      */
    void remove(int id);

    /**
      drag the group to its new parent group
      @param groupId
      the id of chosen group
      @param newParentId
      the id of the chosen group's new parent
      */
    void dragGroup(int groupId, int newParentId);

    /**
      input a new name to the chosen group
      @param id
      the id of the chosen group
      @param newName
      the new name of the chosen group
      */
    void renameGroup(int id, const QString &newName);

private:
    GroupController();
};

#endif // GROUPCONTROLLER_H
