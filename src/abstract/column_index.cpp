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

#include <sqlite-winq/abstract/column.hpp>
#include <sqlite-winq/abstract/column_index.hpp>
#include <sqlite-winq/abstract/expr.hpp>

namespace SQLITEWINQ {

ColumnIndex::ColumnIndex(const Column &column, OrderTerm term)
    : Describable(column.getName()) {
    if (term != OrderTerm::NotSet) {
        m_description.append(" ");
        m_description.append(OrderTermName(term));
    }
}

ColumnIndex::ColumnIndex(const Expr &expr, OrderTerm term)
    : Describable(expr.getDescription()) {
    if (term != OrderTerm::NotSet) {
        m_description.append(" ");
        m_description.append(OrderTermName(term));
    }
}

ColumnIndexList::ColumnIndexList()
    : std::list<const ColumnIndex>() {
}

ColumnIndexList::ColumnIndexList(const ColumnIndex &expr)
    : std::list<const ColumnIndex>({expr}) {
}

ColumnIndexList::ColumnIndexList(size_type __n, const ColumnIndex &expr)
    : std::list<const ColumnIndex>(__n, expr) {
}

ColumnIndexList::ColumnIndexList(std::initializer_list<const ColumnIndex> il)
    : std::list<const ColumnIndex>(il.begin(), il.end()) {
}

}  //namespace SQLITEWINQ

