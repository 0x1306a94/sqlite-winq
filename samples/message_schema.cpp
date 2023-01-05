//
//  message_schema.cpp
//  sqlite-winq-sample
//
//  Created by king on 2023/1/5.
//

#include "message_schema.hpp"

SQLITE_WINQ_IMPLEMENTATION_BEGIN
SQLITE_WINQ_IMPLEMENTATION(MessageSchema, "t_message")

SQLITE_WINQ_SYNTHESIZE(MessageSchema, id)
SQLITE_WINQ_SYNTHESIZE(MessageSchema, uid)
SQLITE_WINQ_SYNTHESIZE(MessageSchema, name)
SQLITE_WINQ_SYNTHESIZE_DEFAULT(MessageSchema, avatar, "")

SQLITE_WINQ_UNIQUE_INDEX(MessageSchema, "_uniqueIndex", uid)
SQLITE_WINQ_UNIQUE_INDEX(MessageSchema, "_uniqueIndex", name)

SQLITE_WINQ_PRIMARY_ASC_AUTO_INCREMENT(MessageSchema, id)
SQLITE_WINQ_NOT_NULL(MessageSchema, uid)
SQLITE_WINQ_NOT_NULL(MessageSchema, name)

SQLITE_WINQ_MULTI_UNIQUE(MessageSchema, "x_uid", id)
SQLITE_WINQ_MULTI_UNIQUE(MessageSchema, "x_uid", uid)

SQLITE_WINQ_IMPLEMENTATION_END

