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

#ifndef sqlite_winq_index_binding_hpp
#define sqlite_winq_index_binding_hpp

#include <sqlite-winq/abstract/declare.hpp>
#include <string>

namespace SQLITEWINQ {

typedef Expr Condition;
class IndexBinding {
  public:
    IndexBinding(const std::string &indexNameSubfix);
    const std::string indexNameSubfix;

    void addIndex(const ColumnIndex &index);
    void setUnique(bool unique);
    void setCondition(const Condition &condition);

    const ColumnIndexList &getIndexes() const;
    const Condition &getCondition() const;

    StatementCreateIndex
    generateCreateIndexStatement(const std::string &tableName) const;

  protected:
    ColumnIndexList m_indexes;
    Condition m_condition;
    bool m_unique;
};

};  // namespace SQLITEWINQ

#endif /* sqlite_winq_index_binding_hpp */

