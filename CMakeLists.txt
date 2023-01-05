cmake_minimum_required(VERSION 3.6)

project(sqlite-winq CXX)


# for build
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility-inlines-hidden")

if(APPLE)
     # for gen xcode project file
    set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "gnu++17")
    set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")

    # for build
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17 -stdlib=libc++")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -g -gline-tables-only")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g -gline-tables-only")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
    
    if (NOT DEFINED ENABLE_BITCODE)
        set(ENABLE_BITCODE TRUE CACHE BOOL "Wheter or not to enable bitcode")
    endif()

    if (ENABLE_BITCODE)
        set(CMAKE_XCODE_ATTRIBUTE_ENABLE_BITCODE "YES")
    else()
        set(CMAKE_XCODE_ATTRIBUTE_ENABLE_BITCODE "NO")
    endif()

    set(CMAKE_XCODE_ATTRIBUTE_STRIP_STYLE "Debuging")
    set(CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET "10.0")
    set(CMAKE_XCODE_ATTRIBUTE_OTHER_LDFLAGS "-ObjC")
    set(CMAKE_XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT "dwarf-with-dsym")
    set(CMAKE_XCODE_ATTRIBUTE_CLANG_DEBUG_INFORMATION_LEVEL[variant=Debug] "default")
    set(CMAKE_XCODE_ATTRIBUTE_CLANG_DEBUG_INFORMATION_LEVEL[variant=Release] "line-tables-only")

    if(DEFINED IOS_DEPLOYMENT_TARGET)
        message(STATUS "setting IOS_DEPLOYMENT_TARGET=${IOS_DEPLOYMENT_TARGET}")
        set(CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET "${IOS_DEPLOYMENT_TARGET}")
    endif()
endif()

include_directories(./include)

file(
  GLOB SELF_TEMP_SRC_FILES
  RELATIVE ${PROJECT_SOURCE_DIR}
  ./include/sqlite-winq/accessor/*.hpp ./include/sqlite-winq/accessor/*.h)
source_group(HEADERS/accessor FILES ${SELF_TEMP_SRC_FILES})
list(APPEND SELF_SRC_FILES ${SELF_TEMP_SRC_FILES})

file(
  GLOB SELF_TEMP_SRC_FILES
  RELATIVE ${PROJECT_SOURCE_DIR}
  ./include/sqlite-winq/abstract/*.hpp ./include/sqlite-winq/abstract/*.h)
source_group(HEADERS/abstract FILES ${SELF_TEMP_SRC_FILES})
list(APPEND SELF_SRC_FILES ${SELF_TEMP_SRC_FILES})

file(
  GLOB SELF_TEMP_SRC_FILES
  RELATIVE ${PROJECT_SOURCE_DIR}
  ./include/sqlite-winq/binding/*.hpp ./include/sqlite-winq/binding/*.h)
source_group(HEADERS/binding FILES ${SELF_TEMP_SRC_FILES})
list(APPEND SELF_SRC_FILES ${SELF_TEMP_SRC_FILES})

file(
  GLOB SELF_TEMP_SRC_FILES
  RELATIVE ${PROJECT_SOURCE_DIR}
  ./include/sqlite-winq/macro/*.hpp ./include/sqlite-winq/macro/*.h)
source_group(HEADERS/macro FILES ${SELF_TEMP_SRC_FILES})
list(APPEND SELF_SRC_FILES ${SELF_TEMP_SRC_FILES})

file(
  GLOB SELF_TEMP_SRC_FILES
  RELATIVE ${PROJECT_SOURCE_DIR}
  ./src/abstract/*.cpp ./src/abstract/*.cc)
source_group(SOURCES/abstract FILES ${SELF_TEMP_SRC_FILES})
list(APPEND SELF_SRC_FILES ${SELF_TEMP_SRC_FILES})

file(
  GLOB SELF_TEMP_SRC_FILES
  RELATIVE ${PROJECT_SOURCE_DIR}
  ./src/binding/*.cpp ./src/binding/*.cc)
source_group(SOURCES/binding FILES ${SELF_TEMP_SRC_FILES})
list(APPEND SELF_SRC_FILES ${SELF_TEMP_SRC_FILES})

file(
  GLOB SELF_TEMP_SRC_FILES
  RELATIVE ${PROJECT_SOURCE_DIR}
  ./src/accessor/*.cpp ./src/accessor/*.cc)
source_group(SOURCES/accessor FILES ${SELF_TEMP_SRC_FILES})
list(APPEND SELF_SRC_FILES ${SELF_TEMP_SRC_FILES})

add_library(${PROJECT_NAME} STATIC ${SELF_SRC_FILES})

add_subdirectory(./samples)
