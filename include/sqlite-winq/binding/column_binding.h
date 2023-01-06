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

#ifndef sqlite_winq_column_binding_hpp
#define sqlite_winq_column_binding_hpp

#include <sqlite-winq/abstract/column_def.hpp>
#include <sqlite-winq/abstract/column_type.hpp>
#include <sqlite-winq/abstract/declare.hpp>
#include <sqlite-winq/abstract/order.hpp>
#include <sqlite-winq/abstract/property.hpp>
#include <sqlite-winq/accessor/cpp_accessor.h>

namespace SQLITEWINQ {

class ColumnBinding {
  public:
    template <typename T>
    ColumnBinding(
        const std::string &pn,
        const std::string &cn,
        T * = nullptr,
        typename std::enable_if<ColumnIsCppType<T>::value>::type * = nullptr)
        : columnName(cn)
        , accessor(new CppAccessor<ColumnInfo<T>::type>())
        , m_columnDef(cn, accessor->getColumnType())
        , m_isAutoIncrement(false)
        , m_isPrimary(false) {
    }

    const std::string columnName;
    const std::shared_ptr<BaseAccessor> accessor;
    bool isPrimary() const;
    bool isAutoIncrement() const;
    const ColumnDef getColumnDef() const;

    void
    makePrimary(OrderTerm order, bool isAutoIncrement, Conflict conflict);

    void makeNotNull();

    void makeUnique();

    template <typename T>
    typename std::enable_if<ColumnIsCppType<T>::value, void>::type
    makeDefault(const typename ColumnInfo<T>::CType &defaultValue) {
        m_columnDef.makeDefault(defaultValue);
    }

    template <typename T>
    void makeDefault(ColumnDef::DefaultType defaultType) {
        m_columnDef.makeDefault(defaultType);
    }

  protected:
    bool m_isPrimary;
    bool m_isAutoIncrement;
    ColumnDef m_columnDef;
};

};     // namespace SQLITEWINQ
#endif /* sqlite_winq_ColumnBinding_hpp */

