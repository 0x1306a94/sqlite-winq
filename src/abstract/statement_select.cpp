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

#include <sqlite-winq/abstract/clause_join.hpp>
#include <sqlite-winq/abstract/column.hpp>
#include <sqlite-winq/abstract/column_result.hpp>
#include <sqlite-winq/abstract/expr.hpp>
#include <sqlite-winq/abstract/order.hpp>
#include <sqlite-winq/abstract/statement_select.hpp>
#include <sqlite-winq/abstract/subquery.hpp>

namespace SQLITEWINQ {

StatementSelect &StatementSelect::from(const JoinClause &joinClause) {
    m_description.append(" FROM " + joinClause.getDescription());
    return *this;
}

StatementSelect &StatementSelect::from(const std::string &tableName) {
    m_description.append(" FROM " + tableName);
    return *this;
}

StatementSelect &StatementSelect::where(const Expr &where) {
    if (!where.isEmpty()) {
        m_description.append(" WHERE " + where.getDescription());
    }
    return *this;
}

StatementSelect &StatementSelect::limit(const Expr &from, const Expr &to) {
    if (!from.isEmpty()) {
        m_description.append(" LIMIT " + from.getDescription());
        if (!to.isEmpty()) {
            m_description.append("," + to.getDescription());
        }
    }
    return *this;
}

StatementSelect &StatementSelect::limit(const Expr &limit) {
    if (!limit.isEmpty()) {
        m_description.append(" LIMIT " + limit.getDescription());
    }
    return *this;
}

StatementSelect &StatementSelect::offset(const Expr &offset) {
    if (!offset.isEmpty()) {
        m_description.append(" OFFSET " + offset.getDescription());
    }
    return *this;
}

StatementSelect &StatementSelect::having(const Expr &having) {
    if (!having.isEmpty()) {
        m_description.append(" HAVING " + having.getDescription());
    }
    return *this;
}

Statement::Type StatementSelect::getStatementType() const {
    return Statement::Type::Select;
}

StatementSelectList::StatementSelectList()
    : std::list<const StatementSelect>() {
}

StatementSelectList::StatementSelectList(const StatementSelect &expr)
    : std::list<const StatementSelect>({expr}) {
}

StatementSelectList::StatementSelectList(std::initializer_list<const StatementSelect> il)
    : std::list<const StatementSelect>(il.begin(), il.end()) {
}
}  //namespace SQLITEWINQ

