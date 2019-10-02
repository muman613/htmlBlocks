#ifndef __HTMLBLOCK_TYPES_H__
#define __HTMLBLOCK_TYPES_H__

#include <cstdint>

#if defined(USE_STL)

    #include <string>
    #include <vector>

    typedef std::string         STRING_T;

#elif defined(USE_QT)

    #include <QString>
    #include <QVector>

    typedef QString             STRING_T;

#endif

#endif // __HTMLBLOCK_TYPES_H__

