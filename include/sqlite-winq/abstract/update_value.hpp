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

#ifndef sqlite_winq_update_value_hpp
#define sqlite_winq_update_value_hpp

#include <sqlite-winq/abstract/declare.hpp>

namespace SQLITEWINQ {
class Column;
class Expr;

typedef std::pair<const Column, const Expr> UpdateValue;

class UpdateValueList : public std::list<const UpdateValue> {
  public:
    UpdateValueList();
    UpdateValueList(const UpdateValue &expr);
    UpdateValueList(std::initializer_list<const UpdateValue> il);
};

}  //namespace SQLITEWINQ

#endif /* sqlite_winq_update_value_hpp */

