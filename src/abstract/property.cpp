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

#include <sqlite-winq/abstract/property.hpp>

namespace SQLITEWINQ {
Property::Property(const char *name)
    : Column(name) {
}

Property::Property(const std::string &name)
    : Column(name) {
}

Property::Property(const Column &column)
    : Column(column) {
}

Property Property::inTable(const std::string &table) const {
    return Property(Column(getName()).inTable(table));
}

Order Property::order(OrderTerm term) const {
    return Order(*this, term);
}

//Index Property::index(OrderTerm term) const
//{
//    return ColumnIndex(*this, (OrderTerm) term);
//}

Expr Property::avg(bool distinct) const {
    return Expr(*this).avg(distinct);
}

Expr Property::count(bool distinct) const {
    return Expr(*this).count(distinct);
}

Expr Property::groupConcat(bool distinct) const {
    return Expr(*this).groupConcat(distinct);
}

Expr Property::groupConcat(const std::string &seperator, bool distinct) const {
    return Expr(*this).groupConcat(seperator, distinct);
}

Expr Property::max(bool distinct) const {
    return Expr(*this).max(distinct);
}

Expr Property::min(bool distinct) const {
    return Expr(*this).min(distinct);
}

Expr Property::sum(bool distinct) const {
    return Expr(*this).sum(distinct);
}

Expr Property::total(bool distinct) const {
    return Expr(*this).total(distinct);
}

Expr Property::abs(bool distinct) const {
    return Expr(*this).abs(distinct);
}

Expr Property::hex(bool distinct) const {
    return Expr(*this).hex(distinct);
}

Expr Property::length(bool distinct) const {
    return Expr(*this).length(distinct);
}

Expr Property::lower(bool distinct) const {
    return Expr(*this).lower(distinct);
}

Expr Property::upper(bool distinct) const {
    return Expr(*this).upper(distinct);
}

Expr Property::round(bool distinct) const {
    return Expr(*this).round(distinct);
}

Expr Property::operator!() const {
    return !Expr(*this);
}

Expr Property::operator+() const {
    return +Expr(*this);
}

Expr Property::operator-() const {
    return -Expr(*this);
}

Expr Property::operator~() const {
    return ~Expr(*this);
}

Expr Property::operator||(const Expr &operand) const {
    return Expr(*this) || operand;
}

Expr Property::operator&&(const Expr &operand) const {
    return Expr(*this) && operand;
}

Expr Property::operator*(const Expr &operand) const {
    return Expr(*this) * operand;
}

Expr Property::operator/(const Expr &operand) const {
    return Expr(*this) / operand;
}

Expr Property::operator%(const Expr &operand) const {
    return Expr(*this) % operand;
}

Expr Property::operator+(const Expr &operand) const {
    return Expr(*this) + operand;
}

Expr Property::operator-(const Expr &operand) const {
    return Expr(*this) - operand;
}

Expr Property::operator<<(const Expr &operand) const {
    return Expr(*this) << operand;
}

Expr Property::operator>>(const Expr &operand) const {
    return Expr(*this) >> operand;
}

Expr Property::operator&(const Expr &operand) const {
    return Expr(*this) & operand;
}

Expr Property::operator|(const Expr &operand) const {
    return Expr(*this) | operand;
}

Expr Property::operator<(const Expr &operand) const {
    return Expr(*this) < operand;
}

Expr Property::operator<=(const Expr &operand) const {
    return Expr(*this) <= operand;
}

Expr Property::operator>(const Expr &operand) const {
    return Expr(*this) > operand;
}

Expr Property::operator>=(const Expr &operand) const {
    return Expr(*this) >= operand;
}

Expr Property::operator==(const Expr &operand) const {
    return Expr(*this) == operand;
}

Expr Property::operator!=(const Expr &operand) const {
    return Expr(*this) != operand;
}

Expr Property::concat(const Expr &operand) const {
    return Expr(*this).concat(operand);
}

Expr Property::substr(const Expr &start, const Expr &length) const {
    return Expr(*this).substr(start, length);
}

Expr Property::in(const ExprList &exprList) const {
    return Expr(*this).in(exprList);
}

Expr Property::notIn(const ExprList &exprList) const {
    return Expr(*this).notIn(exprList);
}

Expr Property::in(const StatementSelectList &statementSelectList) const {
    return Expr(*this).in(statementSelectList);
}

Expr Property::notIn(const StatementSelectList &statementSelectList) const {
    return Expr(*this).notIn(statementSelectList);
}

Expr Property::between(const Expr &left, const Expr &right) const {
    return Expr(*this).between(left, right);
}

Expr Property::notBetween(const Expr &left, const Expr &right) const {
    return Expr(*this).notBetween(left, right);
}

Expr Property::like(const Expr &operand) const {
    return Expr(*this).like(operand);
}

Expr Property::glob(const Expr &operand) const {
    return Expr(*this).glob(operand);
}

Expr Property::match(const Expr &operand) const {
    return Expr(*this).match(operand);
}

Expr Property::regexp(const Expr &operand) const {
    return Expr(*this).regexp(operand);
}

Expr Property::notLike(const Expr &operand) const {
    return Expr(*this).notLike(operand);
}

Expr Property::notGlob(const Expr &operand) const {
    return Expr(*this).notGlob(operand);
}

Expr Property::notMatch(const Expr &operand) const {
    return Expr(*this).notMatch(operand);
}

Expr Property::notRegexp(const Expr &operand) const {
    return Expr(*this).notRegexp(operand);
}

Expr Property::like(const Expr &operand, const Expr &escape) const {
    return Expr(*this).like(operand, escape);
}

Expr Property::glob(const Expr &operand, const Expr &escape) const {
    return Expr(*this).glob(operand, escape);
}

Expr Property::match(const Expr &operand, const Expr &escape) const {
    return Expr(*this).match(operand, escape);
}

Expr Property::regexp(const Expr &operand, const Expr &escape) const {
    return Expr(*this).regexp(operand, escape);
}

Expr Property::notLike(const Expr &operand, const Expr &escape) const {
    return Expr(*this).notLike(operand, escape);
}

Expr Property::notGlob(const Expr &operand, const Expr &escape) const {
    return Expr(*this).notGlob(operand, escape);
}

Expr Property::notMatch(const Expr &operand, const Expr &escape) const {
    return Expr(*this).notMatch(operand, escape);
}

Expr Property::notRegexp(const Expr &operand, const Expr &escape) const {
    return Expr(*this).notRegexp(operand, escape);
}

Expr Property::isNull() const {
    return Expr(*this).isNull();
}

Expr Property::isNotNull() const {
    return Expr(*this).isNotNull();
}

Expr Property::is(const Expr &operand) const {
    return Expr(*this).is(operand);
}

Expr Property::isNot(const Expr &operand) const {
    return Expr(*this).isNot(operand);
}

PropertyList::PropertyList()
    : std::list<const Property>() {
}

PropertyList::PropertyList(const Property &property)
    : std::list<const Property>({property}) {
}

PropertyList::PropertyList(std::initializer_list<const Property> il)
    : std::list<const Property>(il) {
}

PropertyList PropertyList::inTable(const std::string &tableName) const {
    PropertyList propertyList;
    for (auto iter : *this) {
        propertyList.push_back(iter.inTable(tableName));
    }
    return propertyList;
}
};  // namespace SQLITEWINQ

