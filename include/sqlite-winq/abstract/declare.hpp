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

#ifndef sqlite_winq_declare_hpp
#define sqlite_winq_declare_hpp

#include <atomic>
#include <cassert>
#include <functional>
#include <initializer_list>
#include <list>
#include <sqlite-winq/abstract/conflict.hpp>
#include <string>
#include <utility>

namespace SQLITEWINQ {

class Column;
class ColumnDef;
class ColumnIndex;
class ColumnResult;
class Describable;
class Expr;
class JoinClause;
class Order;
class Pragma;
class ModuleArgument;
class Statement;
class StatementAlterTable;
class StatementCreateIndex;
class StatementCreateTable;
class StatementDelete;
class StatementDropIndex;
class StatementDropTable;
class StatementInsert;
class StatementPragma;
class StatementSelect;
class StatementTransaction;
class StatementUpdate;
class StatementCreateVirtualTable;
class Subquery;
class TableConstraint;

typedef std::pair<const Column, const Expr> UpdateValue;

class ResultList;
class ColumnList;
class ColumnDefList;
class ColumnIndexList;
class ColumnResultList;
class ExprList;
class OrderList;
class StatementSelectList;
class SubqueryList;
class TableConstraintList;
class UpdateValueList;
class ModuleArgumentList;

};  //namespace SQLITEWINQ

#endif /* sqlite_winq_declare_hpp */

