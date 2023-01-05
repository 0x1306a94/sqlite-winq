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

#include <sqlite-winq/abstract/expr.hpp>
#include <sqlite-winq/abstract/order.hpp>

namespace SQLITEWINQ {

Order::Order(const Expr &expr, OrderTerm term)
    : Describable(expr.getDescription()) {
    if (term != OrderTerm::NotSet) {
        m_description.append(" ");
        m_description.append(OrderTermName(term));
    }
}

Order::Order(const Expr &expr, const std::string &collation, OrderTerm term)
    : Describable(expr.getDescription()) {
    if (!collation.empty()) {
        m_description.append(" ");
        m_description.append(collation);
    }
    if (term != OrderTerm::NotSet) {
        m_description.append(" ");
        m_description.append(OrderTermName(term));
    }
}

OrderList::OrderList()
    : std::list<const Order>() {
}

OrderList::OrderList(const Order &expr)
    : std::list<const Order>({expr}) {
}

OrderList::OrderList(std::initializer_list<const Order> il)
    : std::list<const Order>(il.begin(), il.end()) {
}

}  //namespace SQLITEWINQ

