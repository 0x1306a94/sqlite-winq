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

#include <sqlite-winq/abstract/result.hpp>

namespace SQLITEWINQ {
Result::Result(const Expr &expr)
    : ColumnResult(expr) {
}

Result::Result(const Property &property)
    : ColumnResult(property) {
}

Result &Result::as(const Property &property) {
    ColumnResult::as(property.getName());
    return *this;
}

ResultList Result::distinct() const {
    return ResultList(*this).distinct();
}

ResultList::ResultList()
    : std::list<const Result>()
    , m_distinct(false) {
}

ResultList::ResultList(const PropertyList &propertyList)
    : std::list<const Result>(propertyList.begin(), propertyList.end())
    , m_distinct(false) {
}

ResultList::ResultList(const ExprList &exprList)
    : std::list<const Result>(exprList.begin(), exprList.end())
    , m_distinct(false) {
}

ResultList::ResultList(std::initializer_list<const Expr> il)
    : std::list<const Result>(il.begin(), il.end())
    , m_distinct(false) {
}

ResultList::ResultList(std::initializer_list<const Property> il)
    : std::list<const Result>(il.begin(), il.end())
    , m_distinct(false) {
}

ResultList &ResultList::distinct() {
    m_distinct = true;
    return *this;
}

bool ResultList::isDistinct() const {
    return m_distinct;
}

ResultList::ResultList(std::initializer_list<const PropertyList> il)
    : std::list<const Result>() {
    for (const auto &propertyList : il) {
        for (const auto &property : propertyList) {
            push_back(property);
        }
    }
}

};  // namespace SQLITEWINQ

