//
//  macro.h
//  sqlite-winq
//
//  Created by king on 2023/1/5.
//

#ifndef sqlite_winq_macro_h
#define sqlite_winq_macro_h

#define _SQLITE_WINQ_CONCAT_JOIN(a, b, c) a##b##c
#define _SQLITE_WINQ_CONCAT(a, b) a##b
#define SQLITE_WINQ_CONCAT(a, b) _SQLITE_WINQ_CONCAT(a, b)
#define SQLITE_WINQ_CONCAT_JOIN(a, b, c) _SQLITE_WINQ_CONCAT_JOIN(a, b, c)
#define SQLITE_WINQ_UNUSED_UNIQUE_ID SQLITE_WINQ_CONCAT(_unused, __COUNTER__)

#define SQLITE_WINQ_BOOL_1 1
#define SQLITE_WINQ_BOOL_0 0
#define SQLITE_WINQ_BOOL_true 1
#define SQLITE_WINQ_BOOL_false 0
#define SQLITE_WINQ_BOOL_TRUE 1
#define SQLITE_WINQ_BOOL_FALSE 0
#define SQLITE_WINQ_BOOL_YES 1
#define SQLITE_WINQ_BOOL_NO 0
#define SQLITE_WINQ_BOOL___objc_yes 1
#define SQLITE_WINQ_BOOL___objc_no 0
#define SQLITE_WINQ_BOOL(var) _SQLITE_WINQ_BOOL(var)
#define _SQLITE_WINQ_BOOL(var) SQLITE_WINQ_BOOL_##var

#define SQLITE_WINQ_IF_ELSE_0(t, f) f
#define SQLITE_WINQ_IF_ELSE_1(t, f) t
#define __SQLITE_WINQ_IF_ELSE(bit, t, f) SQLITE_WINQ_IF_ELSE_##bit(t, f)
#define _SQLITE_WINQ_IF_ELSE(bit, t, f) __SQLITE_WINQ_IF_ELSE(bit, t, f)
#define SQLITE_WINQ_IF_ELSE(cond, t, f) _SQLITE_WINQ_IF_ELSE(SQLITE_WINQ_BOOL(cond), t, f)

#define SQLITE_WINQ_IF_0(t)
#define SQLITE_WINQ_IF_1(t) t
#define __SQLITE_WINQ_IF(bit, t) SQLITE_WINQ_IF_##bit(t)
#define _SQLITE_WINQ_IF(bit, t) __SQLITE_WINQ_IF(bit, t)
#define SQLITE_WINQ_IF(cond, t) _SQLITE_WINQ_IF(SQLITE_WINQ_BOOL(cond), t)

#define SQLITE_WINQ_IF_NOT_0(f) f
#define SQLITE_WINQ_IF_NOT_1(f)
#define __SQLITE_WINQ_IF_NOT(bit, f) SQLITE_WINQ_IF_NOT_##bit(f)
#define _SQLITE_WINQ_IF_NOT(bit, f) __SQLITE_WINQ_IF_NOT(bit, f)
#define SQLITE_WINQ_IF_NOT(cond, f) _SQLITE_WINQ_IF_NOT(SQLITE_WINQ_BOOL(cond), f)

#define _SQLITE_WINQ_STRINGIFY(str) #str
#define SQLITE_WINQ_STRINGIFY(str) _SQLITE_WINQ_STRINGIFY(str)

#ifdef __cplusplus
#define SQLITE_WINQ_EXTERN extern "C" __attribute__((visibility("default")))
#else
#define SQLITE_WINQ_EXTERN extern __attribute__((visibility("default")))
#endif

#endif /* sqlite_winq_macro_h */

