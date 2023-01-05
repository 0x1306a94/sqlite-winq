//
//  message_schema.hpp
//  sqlite-winq-sample
//
//  Created by king on 2023/1/5.
//

#ifndef message_schema_hpp
#define message_schema_hpp

#include <sqlite-winq/macro/coding_macro.h>
#include <string>

class MessageSchema {
  public:
    MessageSchema() {}
    ~MessageSchema() {}

    SQLITE_WINQ_DECLARE_BEGIN

    SQLITE_WINQ_PROPERTY(std::int64_t, id)
    SQLITE_WINQ_PROPERTY(std::string, uid)
    SQLITE_WINQ_PROPERTY(std::string, name)
    SQLITE_WINQ_PROPERTY(std::string, avatar)

    SQLITE_WINQ_DECLARE_END
};

#endif /* message_schema_hpp */

