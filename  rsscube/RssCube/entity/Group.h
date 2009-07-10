// 2009-07-07 吴双 创建框架
// 2009-07-07 吴双 添加注释
// 2009-07-09 孔乂宇 测试通过

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
      Get the id of current group.
      @return
      The id of current group.
      */
    int getId();

    /**
      Get the name of current group.
      @return
      The name of current group.
      */
    QString getName();

    /**
      Get groups included in the specif group.
      @param id
      One group's id
      @return
      The groups collection
      */
    static QVector<Group> getSubGroups(int id);

    /**
      Add one group with its name and parent group's id
      @param parentId
      Parent group's id
      @param name
      New group's name
      @return
      New group's id
      */
    static int addGroup(int parentId, const QString &name);

    /**
      Remove group by id
      @param id
      Group's id
      */
    static void remove(int id);

    /**
      Rename one group
      @param id
      The group's id
      @param name
      The group's new name
      */
    static void renameGroup(int id, const QString &name);

    /**
      Change one group's parent group
      @param id
      The group's id
      @param parentId
      Parent group's id
      */
    static void setParent(int id, int parentId);

private:

    /** group's id */
    int mId;

    /** group's name */
    QString mName;
};

#endif // GROUP_H
