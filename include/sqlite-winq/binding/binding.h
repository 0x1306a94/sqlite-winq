/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef sqlite_winq_binding_hpp
#define sqlite_winq_binding_hpp

#include <list>
#include <map>
#include <sqlite-winq/binding/column_binding.h>
#include <sqlite-winq/binding/constraint_binding.h>
#include <sqlite-winq/binding/index_binding.h>
#include <string>
#include <type_traits>
#include <unordered_map>

namespace SQLITEWINQ {

struct CaseInsensiveComparetor {
    bool operator()(const std::string &lhs, const std::string &rhs) const {
        return strcasecmp(lhs.c_str(), rhs.c_str()) < 0;
    }
};

typedef std::list<std::shared_ptr<ColumnBinding>> ColumnBindingList;

//Case insensitive
typedef std::map<std::string,
                 std::shared_ptr<ColumnBinding>,
                 CaseInsensiveComparetor>
    ColumnBindingMap;
typedef std::unordered_map<std::string, std::shared_ptr<IndexBinding>>
    IndexBindingMap;
typedef std::list<std::shared_ptr<ConstraintBindingBase>>
    ConstraintBindingList;
typedef std::unordered_map<std::string,
                           std::shared_ptr<ConstraintBindingBase>>
    ConstraintBindingMap;

class Binding {
  public:
    Binding();

#pragma mark - Column
    template <typename T>
    std::shared_ptr<ColumnBinding>
    addColumnBinding(const std::string &propertyName,
                     const std::string &columnName) {
        std::shared_ptr<ColumnBinding> columnBinding(new ColumnBinding(propertyName, columnName, (T *)nullptr));
        _addColumnBinding(columnName, columnBinding);
        return columnBinding;
    }

    std::shared_ptr<ColumnBinding>
    getColumnBinding(const Property &property) const;

    std::shared_ptr<IndexBinding>
    getOrCreateIndexBinding(const std::string &indexSubfixName);

    template <typename T>
    typename std::enable_if<std::is_base_of<ConstraintBindingBase, T>::value,
                            T *>::type
    getOrCreateConstraintBinding(const std::string &constraintName) {
        T *constraint = (T *)getConstraint(constraintName, T::type);
        if (!constraint) {
            std::shared_ptr<T> constraintBinding(new T(constraintName));
            addConstraintBinding(
                constraintName,
                std::static_pointer_cast<ConstraintBindingBase>(
                    constraintBinding));
            constraint = constraintBinding.get();
        }
        return constraint;
    }

    const std::shared_ptr<IndexBindingMap> getIndexBindingMap() const;
    const ColumnBindingList &getColumnBindingList() const;
    const ColumnBindingMap &getColumnBindingMap() const;

    const std::shared_ptr<std::list<std::pair<std::string, std::string>>>
    getVirtualTableArgumentList() const;

    void addVirtualTableArgument(const std::string &left,
                                 const std::string &right);
    void setVirtualTableModule(const std::string &moduleName);

    StatementCreateTable
    generateCreateTableStatement(const std::string &tableName) const;
    StatementCreateVirtualTable
    generateVirtualCreateTableStatement(const std::string &tableName) const;

  protected:
    void
    _addColumnBinding(const std::string &propertyName,
                      const std::shared_ptr<ColumnBinding> &columnBinding);
    ConstraintBindingBase *getConstraint(const std::string &constraintName,
                                         ConstraintBindingType type);
    void addConstraintBinding(
        const std::string &constraintName,
        const std::shared_ptr<ConstraintBindingBase> &constraintBinding);

    ColumnBindingMap m_columnBindingMap;    //columnName->column binding
    ColumnBindingList m_columnBindingList;  //ordered column binding

    void lazyInitIndexBinding();
    std::shared_ptr<IndexBindingMap>
        m_indexBindingMap;  //indexName->index binding

    void lazyInitConstraintBinding();
    std::shared_ptr<ConstraintBindingMap>
        m_constraintBindingMap;  //constraintName->constraint binding
    std::shared_ptr<ConstraintBindingList>
        m_constraintBindingList;  //ordered constraint binding

    void lazyInitVirtualTableArgumentList();
    std::shared_ptr<std::list<std::pair<std::string, std::string>>>
        m_virtualTableArgumentList;  //for Virtual Table
    std::string m_virtualTableModuleName;
};

};     // namespace SQLITEWINQ
#endif /* sqlite_winq_binding_hpp */

