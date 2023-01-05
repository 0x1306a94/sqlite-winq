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

#include <sqlite-winq/abstract/column_def.hpp>
#include <sqlite-winq/abstract/constraint_table.hpp>
#include <sqlite-winq/abstract/statement_create_table.hpp>
#include <sqlite-winq/abstract/statement_select.hpp>

namespace SQLITEWINQ {

StatementCreateTable &StatementCreateTable::create(const std::string &table,
                                                   bool ifNotExists) {
    m_description.append("CREATE TABLE ");
    if (ifNotExists) {
        m_description.append("IF NOT EXISTS ");
    }
    m_description.append(table);
    return *this;
}

StatementCreateTable &
StatementCreateTable::as(const StatementSelect &statementSelect) {
    m_description.append(" AS " + statementSelect.getDescription());
    return *this;
}

Statement::Type StatementCreateTable::getStatementType() const {
    return Statement::Type::CreateTable;
}

}  //namespace SQLITEWINQ

