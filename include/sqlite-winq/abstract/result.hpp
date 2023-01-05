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

#ifndef sqlite_winq_result_hpp
#define sqlite_winq_result_hpp

#include <sqlite-winq/abstract/column_result.hpp>

namespace SQLITEWINQ {

class ResultList;
class Property;
class Result : public ColumnResult {
  public:
    Result(const Expr &expr);
    Result(const Property &property);
    Result &as(const Property &property);

    ResultList distinct() const;
};

class ResultList : public std::list<const Result> {
  public:
    ResultList();

    template <typename T = Result>
    ResultList(
        const T &value,
        typename std::enable_if<
            std::is_constructible<Result, T>::value>::type * = nullptr)
        : std::list<const Result>({Result(value)})
        , m_distinct(false) {
    }

    ResultList(std::initializer_list<const Expr> il);
    ResultList(std::initializer_list<const Property> il);

    ResultList(const PropertyList &propertyList);
    ResultList(const ExprList &exprList);

    ResultList(std::initializer_list<const PropertyList> il);

    ResultList &distinct();

    bool isDistinct() const;

  protected:
    bool m_distinct;
};

};  // namespace SQLITEWINQ

#endif /* sqlite_winq_result_hpp */

