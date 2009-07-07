// 2009-07-07 裴小星 创建框架
// 2009-07-07 裴小星 添加注释

#ifndef MACROS_H
#define MACROS_H

/** Use this macro instead of delete to delete a pointer */
#define DELETE(p)      \
        if (p != NULL)  \
        {                \
            delete p;    \
            p = NULL;   \
        }

#endif // MACROS_H
