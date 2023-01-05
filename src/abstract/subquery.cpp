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
#include <sqlite-winq/abstract/statement_select.hpp>
#include <sqlite-winq/abstract/subquery.hpp>

namespace SQLITEWINQ {

Subquery::Subquery(const char *table)
    : Describable(table) {
}

Subquery::Subquery(const std::string &table)
    : Describable(table) {
}

Subquery::Subquery(const JoinClause &joinClause)
    : Describable("(" + joinClause.getDescription() + ")") {
}

Subquery::Subquery(const StatementSelect &statementSelect)
    : Describable("(" + statementSelect.getDescription() + ")") {
}

Subquery &Subquery::as(const std::string &alias) {
    m_description.append(" AS " + alias);
    return *this;
}

SubqueryList::SubqueryList()
    : std::list<const Subquery>() {
}

SubqueryList::SubqueryList(const Subquery &expr)
    : std::list<const Subquery>({expr}) {
}

SubqueryList::SubqueryList(std::initializer_list<const Subquery> il)
    : std::list<const Subquery>(il.begin(), il.end()) {
}

}  //namespace SQLITEWINQ

