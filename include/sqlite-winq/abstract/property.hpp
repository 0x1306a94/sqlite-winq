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

#ifndef sqlite_winq_property_hpp
#define sqlite_winq_property_hpp

#include <sqlite-winq/abstract/abstract.h>

namespace SQLITEWINQ {
class ColumnBinding;

class PropertyBase {
  public:
    PropertyBase(const std::shared_ptr<ColumnBinding> &columnBinding);
    const std::shared_ptr<ColumnBinding> &getColumnBinding() const;

  protected:
    void setBinding(const PropertyBase &other);
    std::shared_ptr<ColumnBinding> m_columnBinding;
};

class Property : public Column, public PropertyBase {
  public:
    Property(const char *name = "");
    Property(const std::string &name = "");
    Property(const Column &column);
    Property(const char *name,
             const std::shared_ptr<ColumnBinding> &columnBinding);

    //distinct
    ResultList distinct() const;

    //table
    Property inTable(const std::string &table) const;

    //order
    Order order(OrderTerm term = OrderTerm::NotSet) const;

    //index
    ColumnIndex index(OrderTerm term = OrderTerm::NotSet) const;

    //aggregate functions
    Expr avg(bool distinct = false) const;
    Expr count(bool distinct = false) const;
    Expr groupConcat(bool distinct = false) const;
    Expr groupConcat(const std::string &seperator, bool distinct = false) const;
    Expr max(bool distinct = false) const;
    Expr min(bool distinct = false) const;
    Expr sum(bool distinct = false) const;
    Expr total(bool distinct = false) const;

    //core functions
    Expr abs(bool distinct = false) const;
    Expr hex(bool distinct = false) const;
    Expr length(bool distinct = false) const;
    Expr lower(bool distinct = false) const;
    Expr upper(bool distinct = false) const;
    Expr round(bool distinct = false) const;

    //def
    ColumnDef def(ColumnType type,
                  bool isPrimary = false,
                  OrderTerm term = OrderTerm::NotSet,
                  bool autoIncrement = false) const;

    //condition
    //unary
    Expr operator!() const;
    Expr operator+() const;
    Expr operator-() const;
    Expr operator~() const;

    //binary
    Expr operator||(const Expr &operand) const;  //or, not concat
    Expr operator&&(const Expr &operand) const;
    Expr operator*(const Expr &operand) const;
    Expr operator/(const Expr &operand) const;
    Expr operator%(const Expr &operand) const;
    Expr operator+(const Expr &operand) const;
    Expr operator-(const Expr &operand) const;
    Expr operator<<(const Expr &operand) const;
    Expr operator>>(const Expr &operand) const;
    Expr operator&(const Expr &operand) const;
    Expr operator|(const Expr &operand) const;
    Expr operator<(const Expr &operand) const;
    Expr operator<=(const Expr &operand) const;
    Expr operator>(const Expr &operand) const;
    Expr operator>=(const Expr &operand) const;
    Expr operator==(const Expr &operand) const;
    Expr operator!=(const Expr &operand) const;

    Expr concat(const Expr &operand) const;
    Expr substr(const Expr &start, const Expr &length) const;

    Expr in(const ExprList &exprList) const;
    Expr notIn(const ExprList &exprList) const;
    Expr in(const StatementSelectList &statementSelectList) const;
    Expr notIn(const StatementSelectList &statementSelectList) const;

    Expr between(const Expr &left, const Expr &right) const;
    Expr notBetween(const Expr &left, const Expr &right) const;

    Expr like(const Expr &operand) const;
    Expr glob(const Expr &operand) const;
    Expr match(const Expr &operand) const;
    Expr regexp(const Expr &operand) const;
    Expr notLike(const Expr &operand) const;
    Expr notGlob(const Expr &operand) const;
    Expr notMatch(const Expr &operand) const;
    Expr notRegexp(const Expr &operand) const;

    Expr like(const Expr &operand, const Expr &escape) const;
    Expr glob(const Expr &operand, const Expr &escape) const;
    Expr match(const Expr &operand, const Expr &escape) const;
    Expr regexp(const Expr &operand, const Expr &escape) const;
    Expr notLike(const Expr &operand, const Expr &escape) const;
    Expr notGlob(const Expr &operand, const Expr &escape) const;
    Expr notMatch(const Expr &operand, const Expr &escape) const;
    Expr notRegexp(const Expr &operand, const Expr &escape) const;

    Expr isNull() const;
    Expr isNotNull() const;
    Expr is(const Expr &operand) const;
    Expr isNot(const Expr &operand) const;

  protected:
    Property(const Column &column,
             const std::shared_ptr<ColumnBinding> &columnBinding);
};

class PropertyList : public std::list<const Property> {
  public:
    PropertyList();
    PropertyList(const Property &property);
    PropertyList(std::initializer_list<const Property> il);

    PropertyList inTable(const std::string &tableName) const;
};

};  // namespace SQLITEWINQ

#endif /* sqlite_winq_property_hpp */

