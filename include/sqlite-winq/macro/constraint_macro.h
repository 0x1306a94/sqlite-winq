//
//  constraint_macro.h
//  sqlite-winq
//
//  Created by king on 2023/1/5.
//

#ifndef sqlite_winq_constraint_macro_h
#define sqlite_winq_constraint_macro_h

//Column Constraint
#define __SQLITE_WINQ_PRIMARY_IMP(CLASS, propertyName, order, autoIncrement, onConflict) \
    static const auto SQLITE_WINQ_UNUSED_UNIQUE_ID = [](SQLITEWINQ::Binding *binding) {  \
        binding->getColumnBinding(CLASS::propertyName())                                 \
            ->makePrimary(order, autoIncrement, onConflict);                             \
        return nullptr;                                                                  \
    }(&(SQLITE_WINQ_BINDING));

#define __SQLITE_WINQ_NOT_NULL_IMP(CLASS, propertyName)                                 \
    static const auto SQLITE_WINQ_UNUSED_UNIQUE_ID = [](SQLITEWINQ::Binding *binding) { \
        binding->getColumnBinding(CLASS::propertyName())->makeNotNull();                \
        return nullptr;                                                                 \
    }(&(SQLITE_WINQ_BINDING));

#define __SQLITE_WINQ_UNIQUE_IMP(CLASS, propertyName)                                   \
    static const auto SQLITE_WINQ_UNUSED_UNIQUE_ID = [](SQLITEWINQ::Binding *binding) { \
        binding->getColumnBinding(CLASS::propertyName())->makeUnique();                 \
        return nullptr;                                                                 \
    }(&(SQLITE_WINQ_BINDING));

//Table Constraint
#define __SQLITE_WINQ_MULTI_PRIMARY_IMP(CLASS, constraintName, propertyName, order)                    \
    static const auto SQLITE_WINQ_UNUSED_UNIQUE_ID = [](SQLITEWINQ::Binding *binding) {                \
        binding->getOrCreateConstraintBinding<SQLITEWINQ::ConstraintPrimaryKeyBinding>(constraintName) \
            ->addPrimaryKey(CLASS::propertyName().index(order));                                       \
        return nullptr;                                                                                \
    }(&(SQLITE_WINQ_BINDING));

#define __SQLITE_WINQ_MULTI_PRIMARY_CONFLICT_IMP(CLASS, constraintName, conflict)                      \
    static const auto SQLITE_WINQ_UNUSED_UNIQUE_ID = [](SQLITEWINQ::Binding *binding) {                \
        binding->getOrCreateConstraintBinding<SQLITEWINQ::ConstraintPrimaryKeyBinding>(constraintName) \
            ->setConflict(conflict);                                                                   \
        return nullptr;                                                                                \
    }(&(SQLITE_WINQ_BINDING));

#define __SQLITE_WINQ_MULTI_UNIQUE_IMP(CLASS, constraintName, propertyName, order)                 \
    static const auto SQLITE_WINQ_UNUSED_UNIQUE_ID = [](SQLITEWINQ::Binding *binding) {            \
        binding->getOrCreateConstraintBinding<SQLITEWINQ::ConstraintUniqueBinding>(constraintName) \
            ->addUnique(CLASS::propertyName().index(order));                                       \
        return nullptr;                                                                            \
    }(&(SQLITE_WINQ_BINDING));

#define __SQLITE_WINQ_MULTI_UNIQUE_CONFLICT_IMP(CLASS, constraintName, conflict)                   \
    static const auto SQLITE_WINQ_UNUSED_UNIQUE_ID = [](SQLITEWINQ::Binding *binding) {            \
        binding->getOrCreateConstraintBinding<SQLITEWINQ::ConstraintUniqueBinding>(constraintName) \
            ->setConflict(conflict);                                                               \
        return nullptr;                                                                            \
    }(&(SQLITE_WINQ_BINDING));

#define __SQLITE_WINQ_CHECK_IMP(CLASS, cosntraintName, expr)                                      \
    static const auto SQLITE_WINQ_UNUSED_UNIQUE_ID = [](SQLITEWINQ::Binding *binding) {           \
        binding->getOrCreateConstraintBinding<SQLITEWINQ::ConstraintCheckBinding>(constraintName) \
            ->makeCheck(expr);                                                                    \
        return nullptr;                                                                           \
    }(&(SQLITE_WINQ_BINDING));

#endif /* sqlite_winq_constraint_macro_h */

