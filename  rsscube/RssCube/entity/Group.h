// 2009-07-07 吴双 构建Group实体类框架

#ifndef GROUP_H
#define GROUP_H

#include <QVector>
#include <QString>

class Group
{
public:
    Group();
    ~Group();

    int getId();
    QString getName();
    static Group getRootGroup();
    static QVector<Group> getSubGroups(int id);
    static int addGroup(int parentId, const QString &name);
    static void removeGroup(int id);
    static void renameGroup(int id, const QString &name);
    static void setParent(int id, int parentId);

private:
    int mId;
    QString mName;
};

#endif // GROUP_H
