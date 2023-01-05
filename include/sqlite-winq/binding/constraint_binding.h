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

#ifndef sqlite_winq_constraint_binding_hpp
#define sqlite_winq_constraint_binding_hpp

#include <sqlite-winq/abstract/declare.hpp>

namespace SQLITEWINQ {

typedef enum : int {
    kConstraintBindingPrimaryKey,
    kConstraintBindingUnique,
    kConstraintBindingCheck,
} ConstraintBindingType;

class ConstraintBindingBase {
  public:
    ConstraintBindingBase(const std::string &name,
                          ConstraintBindingType type);
    const std::string name;
    const ConstraintBindingType type;

    virtual TableConstraint generateConstraint() const = 0;
};

class ConstraintPrimaryKeyBinding : public ConstraintBindingBase {
  public:
    static constexpr const ConstraintBindingType type =
        kConstraintBindingPrimaryKey;
    ConstraintPrimaryKeyBinding(const std::string &name);

    void addPrimaryKey(const ColumnIndex &index);
    void setConflict(Conflict conflict);

    virtual TableConstraint generateConstraint() const override;

  protected:
    Conflict m_conflict;
    ColumnIndexList m_primaryKeyList;
};

class ConstraintUniqueBinding : public ConstraintBindingBase {
  public:
    static constexpr const ConstraintBindingType type =
        kConstraintBindingUnique;
    ConstraintUniqueBinding(const std::string &name);

    void addUnique(const ColumnIndex &index);
    void setConflict(Conflict conflict);

    virtual TableConstraint generateConstraint() const override;

  protected:
    Conflict m_conflict;
    ColumnIndexList m_uniqueList;
};

class ConstraintCheckBinding : public ConstraintBindingBase {
  public:
    static constexpr const ConstraintBindingType type =
        kConstraintBindingCheck;
    ConstraintCheckBinding(const std::string &name);

    void makeCheck(const Expr &expr);
    virtual TableConstraint generateConstraint() const override;

  protected:
    Expr m_check;
};
};  // namespace SQLITEWINQ

#endif /* sqlite_winq_constraint_binding_hpp */

