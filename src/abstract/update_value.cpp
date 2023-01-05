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
#include <sqlite-winq/abstract/expr.hpp>
#include <sqlite-winq/abstract/update_value.hpp>

namespace SQLITEWINQ {

UpdateValueList::UpdateValueList()
    : std::list<const UpdateValue>() {
}

UpdateValueList::UpdateValueList(const UpdateValue &expr)
    : std::list<const UpdateValue>({expr}) {
}

UpdateValueList::UpdateValueList(std::initializer_list<const UpdateValue> il)
    : std::list<const UpdateValue>(il.begin(), il.end()) {
}

}  //namespace SQLITEWINQ

