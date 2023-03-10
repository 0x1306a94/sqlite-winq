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
#include <sqlite-winq/abstract/column_result.hpp>
#include <sqlite-winq/abstract/expr.hpp>

namespace SQLITEWINQ {

ColumnResult::ColumnResult(const Expr &expr)
    : Describable(expr.getDescription()) {
}

ColumnResult::ColumnResult()
    : Describable("") {
}

ColumnResult ColumnResult::Any() {
    return ColumnResult(Column::Any);
}

ColumnResult ColumnResult::Any(const std::string &tableName) {
    return ColumnResult(tableName + ".*");
}

ColumnResult &ColumnResult::as(const std::string &name) {
    m_description.append(" AS " + name);
    return *this;
}

ColumnResultList::ColumnResultList()
    : std::list<const ColumnResult>() {
}

ColumnResultList::ColumnResultList(const ColumnResult &expr)
    : std::list<const ColumnResult>({expr}) {
}

ColumnResultList::ColumnResultList(size_type __n, const ColumnResult &expr)
    : std::list<const ColumnResult>(__n, expr) {
}

ColumnResultList::ColumnResultList(std::initializer_list<const ColumnResult> il)
    : std::list<const ColumnResult>(il.begin(), il.end()) {
}

}  //namespace SQLITEWINQ

