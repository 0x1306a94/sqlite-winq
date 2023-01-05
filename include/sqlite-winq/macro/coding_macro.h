//
//  coding_macro.h
//  sqlite-winq
//
//  Created by king on 2023/1/5.
//

#ifndef sqlite_winq_coding_macro_h
#define sqlite_winq_coding_macro_h

#include <sqlite-winq/abstract/conflict.hpp>
#include <sqlite-winq/abstract/order_term.hpp>
#include <sqlite-winq/abstract/property.hpp>
#include <sqlite-winq/abstract/result.hpp>
#include <sqlite-winq/binding/binding.h>
#include <sqlite-winq/macro/constraint_macro.h>
#include <sqlite-winq/macro/index_macro.h>
#include <sqlite-winq/macro/macro.h>
#include <sqlite-winq/macro/property_macro.h>

#define SQLITE_WINQ_BINDING g_binding
#define SQLITE_WINQ_PROPERTIES g_properties

#define SQLITE_WINQ_IMPLEMENTATION(CLASS, TABLENAME)         \
    const std::string &CLASS::TableName() {                  \
        static std::string tab_name = TABLENAME;             \
        return tab_name;                                     \
    }                                                        \
    static SQLITEWINQ::Binding SQLITE_WINQ_BINDING;          \
    const SQLITEWINQ::Binding &CLASS::Bindings() {           \
        return SQLITE_WINQ_BINDING;                          \
    }                                                        \
    static SQLITEWINQ::PropertyList SQLITE_WINQ_PROPERTIES;  \
    const SQLITEWINQ::PropertyList &CLASS::AllProperties() { \
        return SQLITE_WINQ_PROPERTIES;                       \
    }

/* clang-format off */
#define SQLITE_WINQ_DECLARE_BEGIN \
public: \
    static const std::string &TableName(); \
    static const SQLITEWINQ::Binding &Bindings(); \
    static const SQLITEWINQ::PropertyList &AllProperties();

#define SQLITE_WINQ_DECLARE_END

#define SQLITE_WINQ_IMPLEMENTATION_BEGIN

#define SQLITE_WINQ_IMPLEMENTATION_END
/* clang-format on */

//Property - declare column
#define SQLITE_WINQ_FIELD(TYPE, propertyName) \
    TYPE propertyName;

#define SQLITE_WINQ_PROPERTY(TYPE, propertyName)                          \
    using SQLITE_WINQ_CONCAT_JOIN(propertyName, _, type) = typename TYPE; \
    static const SQLITEWINQ::Property &propertyName();

//Synthesize - implement column
#define SQLITE_WINQ_SYNTHESIZE(CLASS, propertyName) \
    SQLITE_WINQ_SYNTHESIZE_IMP(CLASS, propertyName, #propertyName)

#define SQLITE_WINQ_SYNTHESIZE_COLUMN(CLASS, propertyName, columnName) \
    SQLITE_WINQ_SYNTHESIZE_IMP(CLASS, propertyName, columnName)

#define SQLITE_WINQ_SYNTHESIZE_DEFAULT(CLASS, propertyName, defaultValue) \
    SQLITE_WINQ_SYNTHESIZE_DEFAULT_IMP(CLASS, propertyName, #propertyName, defaultValue)

#define SQLITE_WINQ_SYNTHESIZE_COLUMN_DEFAULT(CLASS, propertyName, columnName, defaultValue) \
    SQLITE_WINQ_SYNTHESIZE_DEFAULT_IMP(CLASS, propertyName, columnName, defaultValue)

//Constraint
//Column Constraint
#define SQLITE_WINQ_PRIMARY(CLASS, propertyName) \
    __SQLITE_WINQ_PRIMARY_IMP(CLASS, propertyName, SQLITEWINQ::OrderTerm::NotSet, false, SQLITEWINQ::Conflict::NotSet)

#define SQLITE_WINQ_PRIMARY_ASC(CLASS, propertyName) \
    __SQLITE_WINQ_PRIMARY_IMP(CLASS, propertyName, SQLITEWINQ::OrderTerm::ASC, false, SQLITEWINQ::Conflict::NotSet)

#define SQLITE_WINQ_PRIMARY_DESC(CLASS, propertyName) \
    __SQLITE_WINQ_PRIMARY_IMP(CLASS, propertyName, SQLITEWINQ::OrderTerm::DESC, false, SQLITEWINQ::Conflict::NotSet)

#define SQLITE_WINQ_PRIMARY_AUTO_INCREMENT(CLASS, propertyName) \
    __SQLITE_WINQ_PRIMARY_IMP(CLASS, propertyName, SQLITEWINQ::OrderTerm::NotSet, true, SQLITEWINQ::Conflict::NotSet)

#define SQLITE_WINQ_PRIMARY_ASC_AUTO_INCREMENT(CLASS, propertyName) \
    __SQLITE_WINQ_PRIMARY_IMP(CLASS, propertyName, SQLITEWINQ::OrderTerm::ASC, true, SQLITEWINQ::Conflict::NotSet)

#define SQLITE_WINQ_PRIMARY_IMP(CLASS, propertyName, order, isAutoIncrement, onConflict) \
    __SQLITE_WINQ_PRIMARY_IMP(CLASS, propertyName, order, isAutoIncrement, onConflict)

#define SQLITE_WINQ_NOT_NULL(CLASS, propertyName) \
    __SQLITE_WINQ_NOT_NULL_IMP(CLASS, propertyName)

#define SQLITE_WINQ_UNIQUE(CLASS, propertyName) \
    __SQLITE_WINQ_UNIQUE_IMP(CLASS, propertyName)

//Table Constraint
#define SQLITE_WINQ_MULTI_PRIMARY(CLASS, constraintName, propertyName) \
    __SQLITE_WINQ_MULTI_PRIMARY_IMP(CLASS, constraintName, propertyName, SQLITEWINQ::OrderTerm::NotSet)

#define SQLITE_WINQ_MULTI_PRIMARY_ASC(CLASS, constraintName, propertyName) \
    __SQLITE_WINQ_MULTI_PRIMARY_IMP(CLASS, constraintName, propertyName, SQLITEWINQ::OrderTerm::ASC)

#define SQLITE_WINQ_MULTI_PRIMARY_DESC(CLASS, constraintName, propertyName) \
    __SQLITE_WINQ_MULTI_PRIMARY_IMP(CLASS, constraintName, propertyName, SQLITEWINQ::OrderTerm::DESC)

#define SQLITE_WINQ_MULTI_PRIMARY_CONFLICT(CLASS, constraintName, onConflict) \
    __SQLITE_WINQ_MULTI_PRIMARY_CONFLICT_IMP(CLASS, constraintName, onConflict)

#define SQLITE_WINQ_MULTI_UNIQUE(CLASS, constraintName, propertyName) \
    __SQLITE_WINQ_MULTI_UNIQUE_IMP(CLASS, constraintName, propertyName, SQLITEWINQ::OrderTerm::NotSet)

#define SQLITE_WINQ_MULTI_UNIQUE_ASC(CLASS, constraintName, propertyName) \
    __SQLITE_WINQ_MULTI_UNIQUE_IMP(CLASS, constraintName, propertyName, SQLITEWINQ::OrderTerm::ASC)

#define SQLITE_WINQ_MULTI_UNIQUE_DESC(CLASS, constraintName, propertyName) \
    __SQLITE_WINQ_MULTI_UNIQUE_IMP(CLASS, constraintName, propertyName, SQLITEWINQ::OrderTerm::DESC)

#define SQLITE_WINQ_MULTI_UNIQUE_CONFLICT(CLASS, constraintName, onConflict) \
    __SQLITE_WINQ_MULTI_UNIQUE_CONFLICT_IMP(CLASS, constraintName, onConflict)

#define SQLITE_WINQ_CHECK(CLASS, constraintName, check) \
    __SQLITE_WINQ_CHECK_IMP(CLASS, constraintName, check)

//Index
#define SQLITE_WINQ_INDEX(CLASS, indexSubfixName, propertyName) \
    __SQLITE_WINQ_INDEX_IMP(CLASS, indexSubfixName, propertyName, SQLITEWINQ::OrderTerm::NotSet, false)

#define SQLITE_WINQ_INDEX_ASC(CLASS, indexSubfixName, propertyName) \
    __SQLITE_WINQ_INDEX_IMP(CLASS, indexSubfixName, propertyName, SQLITEWINQ::OrderTerm::Ascending, false)

#define SQLITE_WINQ_INDEX_DESC(CLASS, indexSubfixName, propertyName) \
    __SQLITE_WINQ_INDEX_IMP(CLASS, indexSubfixName, propertyName, SQLITEWINQ::OrderTerm::Descending, false)

#define SQLITE_WINQ_UNIQUE_INDEX(CLASS, indexSubfixName, propertyName) \
    __SQLITE_WINQ_INDEX_IMP(CLASS, indexSubfixName, propertyName, SQLITEWINQ::OrderTerm::NotSet, true)

#define SQLITE_WINQ_UNIQUE_INDEX_ASC(CLASS, indexSubfixName, propertyName) \
    __SQLITE_WINQ_INDEX_IMP(CLASS, indexSubfixName, propertyName, SQLITEWINQ::OrderTerm::Ascending, true)

#define SQLITE_WINQ_UNIQUE_INDEX_DESC(CLASS, indexSubfixName, propertyName) \
    __SQLITE_WINQ_INDEX_IMP(CLASS, indexSubfixName, propertyName, SQLITEWINQ::OrderTerm::Descending, true)

//Virtual Table Argument
#define SQLITE_WINQ_VIRTUAL_TABLE_ARGUMENT(CLASS, left, right) \
    __SQLITE_WINQ_VIRTUAL_TABLE_ARGUMENT_IMP(CLASS, left, right)

#define SQLITE_WINQ_VIRTUAL_TABLE_TOKENIZE(CLASS, tokenizeName) \
    __SQLITE_WINQ_VIRTUAL_TABLE_ARGUMENT_IMP(CLASS, "tokenize", tokenizeName)

#define SQLITE_WINQ_VIRTUAL_TABLE_MODULE(CLASS, moduleName) \
    __SQLITE_WINQ_VIRTUAL_TABLE_MODULE_IMP(CLASS, moduleName)

#endif /* sqlite_winq_coding_macro_h */

