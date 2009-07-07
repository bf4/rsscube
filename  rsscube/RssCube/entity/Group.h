// 2009-07-07 吴双 创建框架

#ifndef GROUP_H
#define GROUP_H

#include <QVector>
#include <QString>

class Group
{
public:
    Group();
    ~Group();

    /**
      get the current group's Id
      @return
      the current group's Id
      */
    int getId();

    /**
      get the current group's name
      @return
      the current group's name
      */
    QString getName();

    /**
      get all the root groups
      @return
      the root groups collection
      */
    static QVector<Group> getRootGroups();

    /**
      get one group's child groups by id
      @param id
      one group's id
      @return
      the groups collection
      */
    static QVector<Group> getSubGroups(int id);

    /**
      add one group with its name and parent group's id
      @param parentId
      parent group's id
      @param name
      new group's name
      @return
      new group's id
      */
    static int addGroup(int parentId, const QString &name);

    /**
      remove group by id
      @param id
      group's id
      */
    static void removeGroup(int id);

    /**
      rename one group
      @param id
      the group's id
      @param name
      the group's new name
      */
    static void renameGroup(int id, const QString &name);

    /**
      change one group's parent group
      @param id
      the group's id
      @param parentId
      parent group's id
      */
    static void setParent(int id, int parentId);

private:

    /** group's id */
    int mId;

    /** group's name */
    QString mName;
};

#endif // GROUP_H
