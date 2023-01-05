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

#ifndef sqlite_winq_column_result_hpp
#define sqlite_winq_column_result_hpp

#include <sqlite-winq/abstract/declare.hpp>
#include <sqlite-winq/abstract/describable.hpp>

namespace SQLITEWINQ {

class ColumnResult : public Describable {
  public:
    ColumnResult(const Expr &expr);
    ColumnResult &as(const std::string &name);
    static ColumnResult Any();
    static ColumnResult Any(const std::string &tableName);

  protected:
    ColumnResult();
};

class ColumnResultList : public std::list<const ColumnResult> {
  public:
    ColumnResultList();
    ColumnResultList(const ColumnResult &expr);
    ColumnResultList(std::initializer_list<const ColumnResult> il);
};

}  //namespace SQLITEWINQ

#endif /* sqlite_winq_column_result_hpp */

