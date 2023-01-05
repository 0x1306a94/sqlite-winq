//
//  macro_helper.h
//  sqlite-winq
//
//  Created by king on 2023/1/5.
//

#ifndef sqlite_winq_macro_helper_h
#define sqlite_winq_macro_helper_h

#include <sqlite-winq/abstract/property.hpp>
#include <sqlite-winq/abstract/result.hpp>

#define _SQLITE_WINQ_CONCAT(a, b) a##b
#define SQLITE_WINQ_CONCAT(a, b) _SQLITE_WINQ_CONCAT(a, b)
#define SQLITE_WINQ_UNUSED_UNIQUE_ID SQLITE_WINQ_CONCAT(_unused, __COUNTER__)

#define SQLITE_WINQ_PROPERTIES g_properties

#define SQLITE_WINQ_IMPLEMENTATION(CLASS, TABLENAME) \
    const std::string &CLASS::TableName() {          \
        static std::string tab_name = TABLENAME;     \
        return tab_name;                             \
    }                                                \
    static PropertyList SQLITE_WINQ_PROPERTIES;      \
    const PropertyList &CLASS::AllProperties() {     \
        return SQLITE_WINQ_PROPERTIES;               \
    }

/* clang-format off */
#define SQLITE_WINQ_DECLARE_BEGIN(CLASS) \
namespace SQLITEWINQ { \
struct CLASS { \
    static const std::string &TableName(); \
    static const PropertyList &AllProperties();

#define SQLITE_WINQ_DECLARE_END(CLASS) \
}; \
};

#define SQLITE_WINQ_IMPLEMENTATION_BEGIN \
namespace SQLITEWINQ { \

#define SQLITE_WINQ_IMPLEMENTATION_END \
}; \
/* clang-format on */

#define SQLITE_WINQ_PROPERTY(propertyName) \
    static const Property &propertyName();

#define SQLITE_WINQ_SYNTHESIZE_IMP(CLASS, propertyName, columnName) \
    const Property &CLASS::propertyName() {                         \
        static const Property s_propertyName{columnName};           \
        return s_propertyName;                                      \
    }

#define SQLITE_WINQ_SYNTHESIZE(CLASS, propertyName) \
    SQLITE_WINQ_SYNTHESIZE_IMP(CLASS, propertyName, #propertyName)

#define SQLITE_WINQ_SYNTHESIZE_COLUMN(CLASS, propertyName, columnName) \
    SQLITE_WINQ_SYNTHESIZE_IMP(CLASS, propertyName, columnName)

#endif /* sqlite_winq_macro_helper_h */

