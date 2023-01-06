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

#ifndef sqlite_winq_cpp_accessor_hpp
#define sqlite_winq_cpp_accessor_hpp

#include <functional>
#include <sqlite-winq/accessor/base_accessor.h>

namespace SQLITEWINQ {

template <typename T, typename Enable = void>
struct ColumnIsCppType : public std::false_type {
};

template <typename T>
struct ColumnIsCppType<T, typename std::enable_if<ColumnInfo<T>::type != ColumnType::Null>::type>
    : public std::true_type {
};

template <ColumnType T>
class CppAccessor : public BaseAccessor {
  public:
    using CType = typename ColumnTypeInfo<T>::CType;
    CppAccessor() {
    }

    virtual ColumnType getColumnType() const override {
        return T;
    };

    virtual AccessorType getAccessorType() const override {
        return AccessorCpp;
    }
};

template <>
class CppAccessor<ColumnType::BLOB> : public BaseAccessor {
  public:
    using SizeType = typename ColumnTypeInfo<ColumnType::BLOB>::SizeType;
    using CType = typename ColumnTypeInfo<ColumnType::BLOB>::CType;
    CppAccessor() {
    }

    virtual ColumnType getColumnType() const override {
        return ColumnType::BLOB;
    }

    virtual AccessorType getAccessorType() const override {
        return AccessorCpp;
    }
};

};  // namespace SQLITEWINQ

#endif /* sqlite_winq_cpp_accessor_hpp */

