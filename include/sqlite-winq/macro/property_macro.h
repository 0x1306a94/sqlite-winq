//
//  property_macro.h
//  sqlite-winq
//
//  Created by king on 2023/1/5.
//

#ifndef sqlite_winq_property_macro_h
#define sqlite_winq_property_macro_h

//#define SQLITE_WINQ_PROPERTY_TYPE(CLASS, propertyName) \
//    decltype(CLASS{}.SQLITE_WINQ_CONCAT_JOIN(m, _, propertyName))

#define SQLITE_WINQ_PROPERTY_TYPE(CLASS, propertyName) \
    CLASS::SQLITE_WINQ_CONCAT_JOIN(propertyName, _, type)

#define SQLITE_WINQ_SYNTHESIZE_IMP(CLASS, propertyName, columnName)                                           \
    const SQLITEWINQ::Property &CLASS::propertyName() {                                                       \
        static const SQLITEWINQ::Property s_propertyName{columnName};                                         \
        return s_propertyName;                                                                                \
    }                                                                                                         \
    static const auto SQLITE_WINQ_UNUSED_UNIQUE_ID = [](SQLITEWINQ::Binding *binding) {                       \
        binding->addColumnBinding<SQLITE_WINQ_PROPERTY_TYPE(CLASS, propertyName)>(#propertyName, columnName); \
        return nullptr;                                                                                       \
    }(&(SQLITE_WINQ_BINDING));                                                                                \
    static const auto SQLITE_WINQ_UNUSED_UNIQUE_ID = [](SQLITEWINQ::PropertyList &propertyList) {             \
        propertyList.push_back(CLASS::propertyName());                                                        \
        return nullptr;                                                                                       \
    }(SQLITE_WINQ_PROPERTIES);

#define SQLITE_WINQ_SYNTHESIZE_DEFAULT_IMP(CLASS, propertyName, columnName, defaultValue)                                            \
    SQLITE_WINQ_SYNTHESIZE_IMP(CLASS, propertyName, columnName)                                                                      \
    static const auto SQLITE_WINQ_UNUSED_UNIQUE_ID = [](SQLITEWINQ::Binding *binding) {                                              \
        binding->getColumnBinding(CLASS::propertyName())->makeDefault<SQLITE_WINQ_PROPERTY_TYPE(CLASS, propertyName)>(defaultValue); \
        return nullptr;                                                                                                              \
    }(&(SQLITE_WINQ_BINDING));

#endif /* sqlite_winq_property_macro_h */

