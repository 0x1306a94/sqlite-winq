//
//  index_macro.h
//  sqlite-winq
//
//  Created by king on 2023/1/5.
//

#ifndef sqlite_winq_index_macro_h
#define sqlite_winq_index_macro_h

#define __SQLITE_WINQ_INDEX_IMP(CLASS, indexSubfixName, propertyName, order, unique)                \
    static const auto SQLITE_WINQ_UNUSED_UNIQUE_ID = [](SQLITEWINQ::Binding *binding) {             \
        binding->getOrCreateIndexBinding(indexSubfixName)                                           \
            ->addIndex(CLASS::propertyName().index(order));                                         \
        SQLITE_WINQ_IF(unique, binding->getOrCreateIndexBinding(indexSubfixName)->setUnique(true);) \
        return nullptr;                                                                             \
    }(&(SQLITE_WINQ_BINDING));

#define __SQLITE_WINQ_VIRTUAL_TABLE_ARGUMENT_IMP(CLASS, left, right)                    \
    static const auto SQLITE_WINQ_UNUSED_UNIQUE_ID = [](SQLITEWINQ::Binding *binding) { \
        binding->addVirtualTableArgument(left, right);                                  \
        return nullptr;                                                                 \
    }(&(SQLITE_WINQ_BINDING));

#define __SQLITE_WINQ_VIRTUAL_TABLE_MODULE_IMP(CLASS, moduleName)                       \
    static const auto SQLITE_WINQ_UNUSED_UNIQUE_ID = [](SQLITEWINQ::Binding *binding) { \
        binding->setVirtualTableModule(moduleName);                                     \
        return nullptr;                                                                 \
    }(&(SQLITE_WINQ_BINDING));

#endif /* sqlite_winq_index_macro_h */

