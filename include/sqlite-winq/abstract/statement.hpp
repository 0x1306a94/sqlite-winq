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

#ifndef sqlite_winq_statement_hpp
#define sqlite_winq_statement_hpp

#include <sqlite-winq/abstract/describable.hpp>

namespace SQLITEWINQ {

class Statement : public Describable {
  public:
    enum class Type : int {
        None = 0,
        AlterTable,
        CreateIndex,
        CreateTable,
        Delete,
        DropIndex,
        DropTable,
        Insert,
        Pragma,
        Select,
        Transaction,
        Update,
        CreateVirtualTable,
        Attach,
        Detach,
        Explain,
        Savepoint,
        Release,
        Rollback,
        Vacuum,
        Reindex,
    };
    Statement();
    virtual ~Statement();
    virtual Statement::Type getStatementType() const = 0;

    friend std::ostream &operator<<(std::ostream &os, const Statement &s) {
        os << s.getDescription() << ";";
        return os;
    }
};

}  //namespace SQLITEWINQ

#endif /* sqlite_winq_statement_hpp */

