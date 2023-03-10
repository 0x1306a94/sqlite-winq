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

#include <sqlite-winq/abstract/column_index.hpp>
#include <sqlite-winq/abstract/expr.hpp>
#include <sqlite-winq/abstract/statement_create_index.hpp>
#include <sqlite-winq/binding/index_binding.h>

namespace SQLITEWINQ {

IndexBinding::IndexBinding(const std::string &ins)
    : indexNameSubfix(ins)
    , m_unique(false) {
}

void IndexBinding::addIndex(const ColumnIndex &index) {
    m_indexes.push_back(index);
}

void IndexBinding::setUnique(bool unique) {
    m_unique = unique;
}

void IndexBinding::setCondition(const Condition &condition) {
    m_condition = condition;
}

const ColumnIndexList &IndexBinding::getIndexes() const {
    return m_indexes;
}

const Condition &IndexBinding::getCondition() const {
    return m_condition;
}

StatementCreateIndex IndexBinding::generateCreateIndexStatement(const std::string &tableName) const {
    std::string indexName = tableName + indexNameSubfix;
    StatementCreateIndex statementCreateIndex = StatementCreateIndex().create(indexName, m_unique).on(tableName, m_indexes);
    if (!m_condition.isEmpty()) {
        statementCreateIndex.where(m_condition);
    }
    return statementCreateIndex;
}
};  // namespace SQLITEWINQ

