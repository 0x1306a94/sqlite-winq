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

#ifndef sqlite_winq_abstract_h
#define sqlite_winq_abstract_h

#include <sqlite-winq/abstract/describable.hpp>

#include <sqlite-winq/abstract/clause_join.hpp>
#include <sqlite-winq/abstract/column.hpp>
#include <sqlite-winq/abstract/column_def.hpp>
#include <sqlite-winq/abstract/column_index.hpp>
#include <sqlite-winq/abstract/column_result.hpp>
#include <sqlite-winq/abstract/column_type.hpp>
#include <sqlite-winq/abstract/constraint_table.hpp>
#include <sqlite-winq/abstract/expr.hpp>
#include <sqlite-winq/abstract/literal_value.hpp>
#include <sqlite-winq/abstract/module_argument.hpp>
#include <sqlite-winq/abstract/order.hpp>
#include <sqlite-winq/abstract/pragma.hpp>
#include <sqlite-winq/abstract/subquery.hpp>

#include <sqlite-winq/abstract/statement.hpp>
#include <sqlite-winq/abstract/statement_alter_table.hpp>
#include <sqlite-winq/abstract/statement_attach.hpp>
#include <sqlite-winq/abstract/statement_create_index.hpp>
#include <sqlite-winq/abstract/statement_create_table.hpp>
#include <sqlite-winq/abstract/statement_create_virtual_table.hpp>
#include <sqlite-winq/abstract/statement_delete.hpp>
#include <sqlite-winq/abstract/statement_detach.hpp>
#include <sqlite-winq/abstract/statement_drop_index.hpp>
#include <sqlite-winq/abstract/statement_drop_table.hpp>
#include <sqlite-winq/abstract/statement_explain.hpp>
#include <sqlite-winq/abstract/statement_insert.hpp>
#include <sqlite-winq/abstract/statement_pragma.hpp>
#include <sqlite-winq/abstract/statement_reindex.hpp>
#include <sqlite-winq/abstract/statement_release.hpp>
#include <sqlite-winq/abstract/statement_rollback.hpp>
#include <sqlite-winq/abstract/statement_savepoint.hpp>
#include <sqlite-winq/abstract/statement_select.hpp>
#include <sqlite-winq/abstract/statement_transaction.hpp>
#include <sqlite-winq/abstract/statement_update.hpp>
#include <sqlite-winq/abstract/statement_vacuum.hpp>

#endif /* sqlite_winq_abstract_h */

