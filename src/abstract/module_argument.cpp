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
#include <sqlite-winq/abstract/module_argument.hpp>

namespace SQLITEWINQ {

ModuleArgument::ModuleArgument(const TableConstraint &tableConstraint)
    : Describable(tableConstraint.getDescription()) {
}

ModuleArgument::ModuleArgument(const ColumnDef &columnDef)
    : Describable(columnDef.getDescription()) {
}

ModuleArgument::ModuleArgument(const std::string &left,
                               const std::string &right)
    : Describable(left + "=" + right) {
}

ModuleArgumentList::ModuleArgumentList()
    : std::list<const ModuleArgument>() {
}

ModuleArgumentList::ModuleArgumentList(const ModuleArgument &expr)
    : std::list<const ModuleArgument>({expr}) {
}

ModuleArgumentList::ModuleArgumentList(std::initializer_list<const ModuleArgument> il)
    : std::list<const ModuleArgument>(il.begin(), il.end()) {
}

}  //namespace SQLITEWINQ

