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

#ifndef sqlite_winq_runtime_base_accessor_hpp
#define sqlite_winq_runtime_base_accessor_hpp

#include <functional>
#include <string>

namespace SQLITEWINQ {

class RuntimeBaseAccessor {
  protected:
    using InstanceType = void *;
};

template <typename PropertyType>
class RuntimeAccessor : public RuntimeBaseAccessor {
  public:
    using Setter = std::function<void(InstanceType, PropertyType)>;
    using Getter = std::function<PropertyType(InstanceType)>;

    RuntimeAccessor(const std::string &propertyName)
        : getProperty(nullptr)
        , setProperty(nullptr) {
    }

    const Setter setProperty;
    const Getter getProperty;
};

};     // namespace SQLITEWINQ
#endif /* sqlite_winq_runtime_base_accessor_hpp */

