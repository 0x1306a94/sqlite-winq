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

#include <sqlite-winq/binding/column_binding.h>

namespace SQLITEWINQ {

bool ColumnBinding::isPrimary() const {
    return m_isPrimary;
}

bool ColumnBinding::isAutoIncrement() const {
    return m_isAutoIncrement;
}

const ColumnDef ColumnBinding::getColumnDef() const {
    return m_columnDef;
}

void ColumnBinding::makePrimary(OrderTerm order, bool isAutoIncrement, Conflict conflict) {
    m_isPrimary = true;
    m_isAutoIncrement = isAutoIncrement;
    m_columnDef.makePrimary(order, isAutoIncrement, conflict);
}

void ColumnBinding::makeNotNull() {
    m_columnDef.makeNotNull();
}

void ColumnBinding::makeUnique() {
    m_columnDef.makeUnique();
}

};  // namespace SQLITEWINQ

