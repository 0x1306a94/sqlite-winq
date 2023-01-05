//
//  message.cpp
//  sqlite-winq-sample
//
//  Created by king on 2023/1/5.
//

#include "message.hpp"

SQLITE_WINQ_IMPLEMENTATION_BEGIN
SQLITE_WINQ_IMPLEMENTATION(Message, "t_message")

SQLITE_WINQ_SYNTHESIZE_IMP(Message, uid, "uid")

SQLITE_WINQ_IMPLEMENTATION_END

