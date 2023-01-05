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

#include <sqlite-winq/abstract/declare.hpp>
#include <sqlite-winq/abstract/property.hpp>
#include <sqlite-winq/binding/binding.h>

namespace SQLITEWINQ {

Binding::Binding()
    : m_indexBindingMap(nullptr)
    , m_constraintBindingMap(nullptr)
    , m_constraintBindingList(nullptr)
    , m_virtualTableArgumentList(nullptr) {
}

void Binding::_addColumnBinding(const std::string &columnName, const std::shared_ptr<ColumnBinding> &columnBinding) {
    m_columnBindingList.push_back(columnBinding);
    m_columnBindingMap.insert({columnName, columnBinding});
}

std::shared_ptr<ColumnBinding> Binding::getColumnBinding(const Property &property) const {
    auto iter = m_columnBindingMap.find(property.getName());
    return iter != m_columnBindingMap.end() ? iter->second : nullptr;
}

void Binding::lazyInitIndexBinding() {
    if (!m_indexBindingMap) {
        m_indexBindingMap.reset(new IndexBindingMap);
    }
}

std::shared_ptr<IndexBinding> Binding::getOrCreateIndexBinding(const std::string &indexSubfixName) {
    lazyInitIndexBinding();
    auto iter = m_indexBindingMap->find(indexSubfixName);
    if (iter == m_indexBindingMap->end()) {
        std::shared_ptr<IndexBinding> indexBinding(new IndexBinding(indexSubfixName));
        m_indexBindingMap->insert({indexSubfixName, indexBinding});
        return indexBinding;
    }
    return iter->second;
}

const std::shared_ptr<IndexBindingMap> Binding::getIndexBindingMap() const {
    return m_indexBindingMap;
}

const ColumnBindingList &Binding::getColumnBindingList() const {
    return m_columnBindingList;
}

const ColumnBindingMap &Binding::getColumnBindingMap() const {
    return m_columnBindingMap;
}

void Binding::lazyInitConstraintBinding() {
    if (!m_constraintBindingList) {
        m_constraintBindingList.reset(new ConstraintBindingList);
    }
    if (!m_constraintBindingMap) {
        m_constraintBindingMap.reset(new ConstraintBindingMap);
    }
}

ConstraintBindingBase *Binding::getConstraint(const std::string &constraintName, ConstraintBindingType type) {
    if (!m_constraintBindingMap) {
        return nullptr;
    }
    auto iter = m_constraintBindingMap->find(constraintName);
    if (iter != m_constraintBindingMap->end()) {
        ConstraintBindingBase *constraintBinding = iter->second.get();
        if (constraintBinding->type == type) {
            return constraintBinding;
        }
    }
    return nullptr;
}

void Binding::addConstraintBinding(const std::string &constraintName, const std::shared_ptr<ConstraintBindingBase> &constraintBinding) {
    lazyInitConstraintBinding();
    m_constraintBindingMap->insert({constraintName, constraintBinding});
    m_constraintBindingList->push_back(constraintBinding);
}

const std::shared_ptr<std::list<std::pair<std::string, std::string>>> Binding::getVirtualTableArgumentList() const {
    return m_virtualTableArgumentList;
}

void Binding::lazyInitVirtualTableArgumentList() {
    if (!m_virtualTableArgumentList) {
        m_virtualTableArgumentList.reset(new std::list<std::pair<std::string, std::string>>);
    }
}

void Binding::addVirtualTableArgument(const std::string &left, const std::string &right) {
    lazyInitVirtualTableArgumentList();
    m_virtualTableArgumentList->push_back({left, right});
}

StatementCreateTable Binding::generateCreateTableStatement(const std::string &tableName) const {
    ColumnDefList columnDefList;
    for (const auto &columnBinding : m_columnBindingList) {
        if (columnBinding) {
            columnDefList.push_back(columnBinding->getColumnDef());
        }
    }
    TableConstraintList constraintList;
    if (m_constraintBindingList) {
        for (const auto &constraintBinding : *m_constraintBindingList.get()) {
            constraintList.push_back(constraintBinding->generateConstraint());
        }
    }
    return StatementCreateTable().create(tableName, columnDefList, constraintList);
}

StatementCreateVirtualTable Binding::generateVirtualCreateTableStatement(const std::string &tableName) const {
    ModuleArgumentList moduleArgumentList;
    for (const auto &columnBinding : m_columnBindingList) {
        moduleArgumentList.push_back(columnBinding->getColumnDef());
    }
    if (m_constraintBindingList) {
        for (const auto &constraintBinding : *m_constraintBindingList.get()) {
            moduleArgumentList.push_back(constraintBinding->generateConstraint());
        }
    }
    if (m_virtualTableArgumentList) {
        for (const auto &moduleArgument : *m_virtualTableArgumentList.get()) {
            moduleArgumentList.push_back(ModuleArgument(moduleArgument.first, moduleArgument.second));
        }
    }
    return StatementCreateVirtualTable().create(tableName).usingModule(m_virtualTableModuleName, moduleArgumentList);
}

void Binding::setVirtualTableModule(const std::string &moduleName) {
    m_virtualTableModuleName = moduleName;
}

};  // namespace SQLITEWINQ

