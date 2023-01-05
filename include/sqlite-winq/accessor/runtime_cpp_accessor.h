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

#ifndef sqlite_winq_runtime_cpp_accessor_hpp
#define sqlite_winq_runtime_cpp_accessor_hpp

#include <sqlite-winq/accessor/cpp_accessor.h>
#include <sqlite-winq/accessor/runtime_base_accessor.h>
#include <string>
#include <type_traits>

namespace SQLITEWINQ {

template <typename PropertyType, typename Enable = void>
class RuntimeCppAccessor {
};

template <typename PropertyType>
class RuntimeCppAccessor<
    PropertyType,
    typename std::enable_if<ColumnInfo<PropertyType>::isBaseType>::type>
    : public RuntimeAccessor<PropertyType>,
      public CppAccessor<ColumnInfo<PropertyType>::type> {
  protected:
    using CppAccessor =
        CppAccessor<ColumnInfo<PropertyType>::type>;
    using RuntimeAccessor = RuntimeAccessor<PropertyType>;
    using InstanceType = typename RuntimeAccessor::InstanceType;
    using CType = typename CppAccessor::CType;
    using PropertyGetter = typename RuntimeAccessor::Getter;
    using PropertySetter = typename RuntimeAccessor::Setter;
    using ValueGetter = typename CppAccessor::Getter;
    using ValueSetter = typename CppAccessor::Setter;

  public:
    RuntimeCppAccessor(const std::string &propertyName)
        : RuntimeAccessor(propertyName)
        , CppAccessor(generateValueGetter(), generateValueSetter()) {
    }

  protected:
    CType convertPropertyTypeToCType(const PropertyType &property) {
        return TypeConverter<CType>::convert(property);
    }

    PropertyType convertCTypeToPropertyType(CType value) {
        return (PropertyType)value;
    }

    ValueGetter generateValueGetter() {
        return [&](InstanceType instance) -> CType {
            return this->convertPropertyTypeToCType(this->getProperty(instance));
        };
    }

    ValueSetter generateValueSetter() {
        return [&](InstanceType instance, CType value) {
            this->setProperty(instance, this->convertCTypeToPropertyType(value));
        };
    }
};

template <typename PropertyType>
class RuntimeCppAccessor<
    PropertyType,
    typename std::enable_if<ColumnInfo<PropertyType>::isBLOB>::type>
    : public RuntimeAccessor<PropertyType>,
      public CppAccessor<ColumnInfo<PropertyType>::type> {
  public:
    using CppAccessor = CppAccessor<ColumnInfo<PropertyType>::type>;
    using RuntimeAccessor = RuntimeAccessor<PropertyType>;
    using InstanceType = typename RuntimeAccessor::InstanceType;
    using CType = typename CppAccessor::CType;
    using SizeType = typename CppAccessor::SizeType;
    using PropertyGetter = typename RuntimeAccessor::Getter;
    using PropertySetter = typename RuntimeAccessor::Setter;
    using ValueGetter = typename CppAccessor::Getter;
    using ValueSetter = typename CppAccessor::Setter;

    RuntimeCppAccessor(const std::string &propertyName)
        : RuntimeAccessor(propertyName)
        , CppAccessor(generateValueGetter(), generateValueSetter()) {
    }

    // no default implementation for BLOB
    //    CType convertPropertyTypeToCType(const PropertyType& property, SizeType& size);
    //    PropertyType convertCTypeToPropertyType(CType value, SizeType size);

    ValueGetter generateValueGetter() {
        return [&](InstanceType instance, SizeType &size) -> CType {
            return this->convertPropertyTypeToCType(this->getProperty(instance), size);
        };
    }

    ValueSetter generateValueSetter() {
        return [&](InstanceType instance, CType value, SizeType size) {
            this->setProperty(instance, this->convertCTypeToPropertyType(value, size));
        };
    }
};

};     // namespace SQLITEWINQ
#endif /* sqlite_winq_runtime_cpp_accessor_hpp */

