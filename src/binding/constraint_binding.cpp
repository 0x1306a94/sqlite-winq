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
#include <sqlite-winq/abstract/conflict.hpp>
#include <sqlite-winq/abstract/constraint_table.hpp>
#include <sqlite-winq/abstract/expr.hpp>
#include <sqlite-winq/binding/constraint_binding.h>

namespace SQLITEWINQ {
ConstraintBindingBase::ConstraintBindingBase(const std::string &n, ConstraintBindingType t)
    : name(n)
    , type(t) {
}

ConstraintPrimaryKeyBinding::ConstraintPrimaryKeyBinding(const std::string &name)
    : ConstraintBindingBase(name, ConstraintPrimaryKeyBinding::type)
    , m_conflict(Conflict::NotSet) {
}

void ConstraintPrimaryKeyBinding::addPrimaryKey(const ColumnIndex &index) {
    m_primaryKeyList.push_back(index);
}

void ConstraintPrimaryKeyBinding::setConflict(Conflict conflict) {
    m_conflict = conflict;
}

TableConstraint ConstraintPrimaryKeyBinding::generateConstraint() const {
    return TableConstraint(name).makePrimary(m_primaryKeyList).onConflict((Conflict)m_conflict);
}

ConstraintUniqueBinding::ConstraintUniqueBinding(const std::string &name)
    : ConstraintBindingBase(name, ConstraintUniqueBinding::type)
    , m_conflict(Conflict::NotSet) {
}

void ConstraintUniqueBinding::addUnique(const ColumnIndex &index) {
    m_uniqueList.push_back(index);
}

void ConstraintUniqueBinding::setConflict(Conflict conflict) {
    m_conflict = conflict;
}

TableConstraint ConstraintUniqueBinding::generateConstraint() const {
    return TableConstraint(name).makeUnique(m_uniqueList).onConflict((Conflict)m_conflict);
}

ConstraintCheckBinding::ConstraintCheckBinding(const std::string &name)
    : ConstraintBindingBase(name, ConstraintCheckBinding::type) {
}

void ConstraintCheckBinding::makeCheck(const Expr &expr) {
    m_check = expr;
}

TableConstraint ConstraintCheckBinding::generateConstraint() const {
    return TableConstraint(name).makeCheck(m_check);
}
};  // namespace SQLITEWINQ

