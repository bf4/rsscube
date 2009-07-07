#ifndef MACROS_H
#define MACROS_H

#define DELETE(p)      \
        if (p != NULL)  \
        {                \
            delete p;    \
            p = NULL;   \
        }

#endif // MACROS_H
