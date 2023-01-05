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

#ifndef sqlite_winq_order_hpp
#define sqlite_winq_order_hpp

#include <sqlite-winq/abstract/declare.hpp>
#include <sqlite-winq/abstract/describable.hpp>
#include <sqlite-winq/abstract/order_term.hpp>

namespace SQLITEWINQ {

class Order : public Describable {
  public:
    Order(const Expr &expr,
          const std::string &collation,
          OrderTerm term = OrderTerm::NotSet);

    Order(const Expr &expr, OrderTerm term = OrderTerm::NotSet);
};

class OrderList : public std::list<const Order> {
  public:
    OrderList();
    OrderList(const Order &expr);
    OrderList(std::initializer_list<const Order> il);
};

}  //namespace SQLITEWINQ

#endif /* sqlite_winq_order_hpp */

